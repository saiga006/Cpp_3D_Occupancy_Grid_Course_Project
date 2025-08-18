#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
#include "occupancy_grid.hpp"
#include "data_analyser.hpp"
#include "scan_processor.hpp"
#include "visualizer.hpp"
//#define TEST

constexpr float OCCUPANCY_THRESHOLD = 0.5f;

void printTimingStats(const std::vector<double>& scan_times, double total_time) {
    std::cout << "=== SCAN STATISTICS ===" << std::endl;
    if (scan_times.empty()) {

        std::cout << "No scan data available!" << std::endl;
        return;
    }
    
    double avg_scan_time = std::reduce(scan_times.begin(), scan_times.end(), 0.0,std::plus<double>()) / scan_times.size();
    const auto [min,max] = std::minmax_element(begin(scan_times), end(scan_times));
    std::cout << "Total scans processed: " << scan_times.size() << std::endl;
    std::cout << "Total execution time: " << total_time << " seconds" << std::endl;
    std::cout << "Best scan time: " << *min << " seconds " << "Worst scan time: " << *max << " seconds " << std::endl;
    std::cout << "Average time per scan: " << avg_scan_time * 1000 << " ms" << std::endl;
    std::cout << "Scan rate: " << scan_times.size() / total_time << " scans/second" << std::endl;
}




int main(int argc, char* argv[]) {

#ifndef TEST
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <data_directory>" << std::endl;
        return -1;
    }
    
    const std::string data_dir = argv[1];
    auto start_analys_time = std::chrono::high_resolution_clock::now();
    // Load dataset
    std::cout << "Loading dataset..." << std::endl;
    dataloader::Dataset dataset(data_dir);
    std::cout << "Found " << dataset.size() << " scans" << std::endl;
    
    // Analyze workspace to determine optimal grid parameters
    std::cout << "\n=== ANALYZING WORKSPACE ===" << std::endl;
    WorkspaceBounds bounds = DataAnalyzer::analyzeDataset(dataset, true);
    bounds.printSummary();
    auto end_analys_time = std::chrono::high_resolution_clock::now();
    double total_analysis_time = std::chrono::duration<double>(end_analys_time - start_analys_time).count();
    std::cout << "Dataset Analysis time: " << total_analysis_time << " seconds " << std::endl;
    // Determine optimal parameters
    double resolution = 0.1;  // 10cm voxels - adjust as needed
    double safety_margin = 0.10;  // 10% margin around workspace
    
    Eigen::Vector3d optimal_origin = DataAnalyzer::estimateOptimalOrigin(bounds, safety_margin);
    std::array<size_t, 3> grid_dims = DataAnalyzer::estimateGridDimensions(bounds, resolution, safety_margin);
    
    // Calculate memory usage
    size_t total_voxels = grid_dims[0] * grid_dims[1] * grid_dims[2];
    double memory_mb = (total_voxels * sizeof(float)) / (1024.0 * 1024.0);
    
    std::cout << "\n=== OPTIMAL GRID CONFIGURATION ===" << std::endl;
    std::cout << "Origin: " << optimal_origin.transpose() << std::endl;
    std::cout << "Dimensions: " << grid_dims[0] << "×" << grid_dims[1] << "×" << grid_dims[2] << std::endl;
    std::cout << "Resolution: " << resolution << "m (" << (resolution*100) << "cm voxels)" << std::endl;
    std::cout << "Total voxels: " << total_voxels << std::endl;
    std::cout << "Estimated memory: " << memory_mb << " MB" << std::endl;
    std::cout << "Grid covers: [" << optimal_origin.transpose() << "] to [" 
              << (optimal_origin + Eigen::Vector3d(grid_dims[0]*resolution, grid_dims[1]*resolution, grid_dims[2]*resolution)).transpose() << "]" << std::endl;
    
    // Warn if memory usage is too high
    if (memory_mb > 5000) {  // > 5GB
        std::cout << "WARNING: Large memory usage! Consider:" << std::endl;
        std::cout << "  - Increasing resolution (e.g., 0.2m instead of 0.1m)" << std::endl;
        std::cout << "  - Reducing safety margin" << std::endl;
        std::cout << "  - Processing subset of data first" << std::endl;
        std::cout << "\n=== APPLYING OPTIMIZATIONS ===" << std::endl;
        
        // Auto-adjust resolution
        double target_memory_gb = 5.0;  // Target 2GB
        double volume = bounds.range.x() * bounds.range.y() * bounds.range.z();
        double target_voxels = (target_memory_gb * 1024 * 1024 * 1024) / sizeof(float);
        double optimized_resolution = std::pow(volume / target_voxels, 1.0/3.0);
        
        resolution = std::max(optimized_resolution, 0.5);  // Minimum 50cm
        safety_margin = 0.01;  // Reduced safety margin
        
        std::cout << "Auto-adjusted resolution to: " << resolution << "m" << std::endl;
        
        // Recalculate with optimized parameters
        optimal_origin = DataAnalyzer::estimateOptimalOrigin(bounds, safety_margin);
        grid_dims = DataAnalyzer::estimateGridDimensions(bounds, resolution, safety_margin);
        
        // Recalculate memory
        total_voxels = grid_dims[0] * grid_dims[1] * grid_dims[2];
        memory_mb = (total_voxels * sizeof(float)) / (1024.0 * 1024.0);
        
        std::cout << "Optimized memory usage: " << memory_mb << " MB" << std::endl;
    
        std::cout << "\n=== OPTIMIZED GRID CONFIGURATION ===" << std::endl;
        std::cout << "Origin: " << optimal_origin.transpose() << std::endl;
        std::cout << "Dimensions: " << grid_dims[0] << "×" << grid_dims[1] << "×" << grid_dims[2] << std::endl;
        std::cout << "Resolution: " << resolution << "m (" << (resolution*100) << "cm per voxels)" << std::endl;
        std::cout << "Total voxels: " << total_voxels << std::endl;
        std::cout << "Estimated memory: " << memory_mb << " MB" << std::endl;
        std::cout << "Grid covers: [" << optimal_origin.transpose() << "] to [" 
                << (optimal_origin + Eigen::Vector3d(grid_dims[0]*resolution, grid_dims[1]*resolution, grid_dims[2]*resolution)).transpose() << "]" << std::endl;
    }

    std::cout << "\n=== STARTING MAPPING ===" << std::endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    // Create optimally sized grid
    OccupancyGrid grid(grid_dims, resolution, optimal_origin);
    auto end_time = std::chrono::high_resolution_clock::now();
    double total_time = std::chrono::duration<double>(end_time - start_time).count();
    std::cout << "Grid creation time: " << total_time << " seconds " << std::endl;
    
    std::cout << "\n=== PROCESSING LIDAR SCANS ===" << std::endl;
    std::vector<double> scan_times;
    scan_times.reserve(dataset.size());

    auto mapping_start = std::chrono::high_resolution_clock::now();

    // test var
    int scan_count = 0;
    // Process each scan
    for (size_t i = 0; i < dataset.size(); ++i) {
        auto scan_start = std::chrono::high_resolution_clock::now();
        
        // Load pose and pointcloud from the dataset
        const auto& [pose, pointcloud] = dataset[i];
        
        // Process the scan using your function
        ScanProcessor::processLidarScan(grid, pose, pointcloud);
        
        auto scan_end = std::chrono::high_resolution_clock::now();
        double scan_time = std::chrono::duration<double>(scan_end - scan_start).count();
        scan_times.emplace_back(scan_time);
        
        // Progress indicator
        if (i % (dataset.size() / 10) == 0) {
            std::cout << "Mapped :: " << i << "/" << dataset.size() << " scans..." << std::endl;
            scan_count++;
            if (scan_count > 1) {
                // uncomment only for debugging incase of performance bottleneck: for now: restrict the scan processing to 10% of lidar dataset, as the scan time reaches 250 seconds.
                //break;
            }
        }
    }

    auto mapping_end = std::chrono::high_resolution_clock::now();
    double total_mapping_time = std::chrono::duration<double>(mapping_end - mapping_start).count();

    std::cout << "Mapping completed!" << std::endl;
    printTimingStats(scan_times, total_mapping_time);

    std::cout << "=== EXTRACTING OCCUPIED VOXELS ===" << std::endl;
    auto extraction_start = std::chrono::high_resolution_clock::now();
    Vector3dVector occupied_voxels = grid.getOccupiedVoxels(OCCUPANCY_THRESHOLD);
    auto extraction_end = std::chrono::high_resolution_clock::now();
    double extraction_time = std::chrono::duration<double>(extraction_end - extraction_start).count();
    std::cout << "Voxel extraction time: " << extraction_time << " seconds." << std::endl;

    if(!occupied_voxels.empty()) {

        std::cout << "Visualising Voxels using open3D ===" << std::endl;
        std::cout << "Visualizing " << occupied_voxels.size() << " occupied voxels..." << std::endl;
        auto viz_start = std::chrono::high_resolution_clock::now();
        visualize(occupied_voxels);  // Calls open3d API
        auto viz_end = std::chrono::high_resolution_clock::now();
        double viz_time = std::chrono::duration<double>(viz_end - viz_start).count();
        std::cout << "Visualization time: " << viz_time << " seconds." << std::endl;
    } else {
        std::cout << "No occupied voxels found! Check mapping pipeline." <<  std::endl;
    }



 #else
        // Test with small grid first
    std::cout << "=== TESTING BASIC FUNCTIONALITY ===" << std::endl;
    
    std::array<size_t, 3> test_dims = {50, 50, 25}; // Small test grid
    double test_resolution = 1.0; // 1m voxels for testing
    Vector3d test_origin(-25.0, -25.0, 0.0);
    
    OccupancyGrid grid(test_dims, test_resolution, test_origin);
    
    // Test coordinate conversions
    Vector3d test_world(5.5, -3.2, 2.8);
    Vector3i test_grid = grid.world_to_grid(test_world);
    Vector3d back_world = grid.grid_to_world(test_grid);
    
    std::cout << "Coordinate Conversion Test:" << std::endl;
    std::cout << "  World: " << test_world.transpose() << std::endl;
    std::cout << "  Grid: " << test_grid.transpose() << std::endl;
    std::cout << "  Back to World: " << back_world.transpose() << std::endl;
    std::cout << "  In Bounds: " << (grid.is_InBounds(test_grid) ? "YES" : "NO") << std::endl;
    
    // Test occupancy updates
    grid.update_occupied(test_grid);
    std::cout << "  Occupancy after update: " << grid.getOccupancy(test_grid) << std::endl;
    
    // Test multiple updates
    for (int i = 0; i < 5; ++i) {
        grid.update_occupied(test_grid);
    }
    std::cout << "  Occupancy after 5 updates: " << grid.getOccupancy(test_grid) << std::endl;
    
    std::cout << "\n=== BASIC FUNCTIONALITY TEST COMPLETED ===" << std::endl;
 #endif


    return 0;
}
