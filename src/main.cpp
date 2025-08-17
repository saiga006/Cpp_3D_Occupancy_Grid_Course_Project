#include <iostream>
#include "occupancy_grid.hpp"
#include "data_analyser.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <data_directory>" << std::endl;
        return -1;
    }
    
    const std::string data_dir = argv[1];
    
    // Load dataset
    std::cout << "Loading dataset..." << std::endl;
    dataloader::Dataset dataset(data_dir);
    std::cout << "Found " << dataset.size() << " scans" << std::endl;
    
    // Analyze workspace to determine optimal grid parameters
    std::cout << "\n=== ANALYZING WORKSPACE ===" << std::endl;
    WorkspaceBounds bounds = DataAnalyzer::analyzeDataset(dataset, true);
    bounds.printSummary();
    
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
        
        resolution = std::max(optimized_resolution, 0.2);  // Minimum 20cm
        safety_margin = 0.05;  // Reduced safety margin
        
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


    
    // Create optimally sized grid
    //OccupancyGrid grid(grid_dims, resolution, optimal_origin);
    
    std::cout << "\n=== STARTING MAPPING ===" << std::endl;
    
    return 0;
}
