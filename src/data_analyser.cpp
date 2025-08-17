#include "data_analyser.hpp"
#include <iostream>
#include <algorithm>

WorkspaceBounds DataAnalyzer::analyzeDataset(const dataloader::Dataset& dataset, 
                                                 bool include_sensor_points) {
    // Initialize bounds with extreme values
    Eigen::Vector3d min_coords(1e9, 1e9, 1e9);
    Eigen::Vector3d max_coords(-1e9, -1e9, -1e9);
    size_t total_points = 0;
    
    std::cout << "Analyzing " << dataset.size() << " poses..." << std::endl;
    
    for (size_t idx = 0; idx < dataset.size(); ++idx) {
        const auto& [pose, sensor_points] = dataset[idx];
        
        // Extract robot position from pose matrix (translation part)
        Eigen::Vector3d robot_pos(pose(0,3), pose(1,3), pose(2,3));
        
        // Update bounds with robot position
        min_coords = min_coords.cwiseMin(robot_pos);
        max_coords = max_coords.cwiseMax(robot_pos);
        
        if (include_sensor_points) {
            // Transform sensor points to world frame and include in bounds
            for (const auto& sensor_point : sensor_points) {
                // Manual transformation
                Eigen::Vector4d point_homogeneous;
                point_homogeneous(0) = sensor_point(0);
                point_homogeneous(1) = sensor_point(1);
                point_homogeneous(2) = sensor_point(2);
                point_homogeneous(3) = 1.0;
                
                Eigen::Vector4d world_point_h = pose * point_homogeneous;
                Eigen::Vector3d world_point = world_point_h.head<3>();
                
                // Update bounds
                min_coords = min_coords.cwiseMin(world_point);
                max_coords = max_coords.cwiseMax(world_point);
                total_points++;
            }
        }
        
        // Progress indicator
        if (idx % (dataset.size() / 10) == 0) {
            std::cout << "Processed " << idx << "/" << dataset.size() << " scans..." << std::endl;
        }
    }
    
    Eigen::Vector3d range = max_coords - min_coords;
    
    return {min_coords, max_coords, range, dataset.size(), total_points};
}

Eigen::Vector3d DataAnalyzer::estimateOptimalOrigin(const WorkspaceBounds& bounds, 
                                                        double safety_margin) {
    // Add safety margin around the workspace
    Eigen::Vector3d margin = bounds.range * safety_margin;
    Eigen::Vector3d optimal_origin = bounds.min_coords - margin;
    
    // Optional: Round to nice numbers for easier debugging
    for (int i = 0; i < 3; ++i) {
        optimal_origin(i) = std::floor(optimal_origin(i) * 10.0) / 10.0; // Round to 0.1m
    }
    
    return optimal_origin;
}

std::array<size_t, 3> DataAnalyzer::estimateGridDimensions(const WorkspaceBounds& bounds,
                                                              double resolution,
                                                              double safety_margin) {
    // Calculate total range including margins
    Eigen::Vector3d margin = bounds.range * safety_margin;
    Eigen::Vector3d total_range = bounds.range + 2.0 * margin; // margin on both sides
    
    std::array<size_t, 3> dimensions;
    for (int i = 0; i < 3; ++i) {
        dimensions[i] = static_cast<size_t>(std::ceil(total_range(i) / resolution));
        
        // Ensure minimum dimensions
        dimensions[i] = std::max(dimensions[i], static_cast<size_t>(10));
    }
    
    return dimensions;
}


