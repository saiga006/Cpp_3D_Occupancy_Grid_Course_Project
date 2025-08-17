#pragma once
#include <Eigen/Core>
#include "dataloader.hpp"
#include <iostream>

struct WorkspaceBounds {
    Eigen::Vector3d min_coords;
    Eigen::Vector3d max_coords;
    Eigen::Vector3d range;
    size_t total_poses;
    size_t total_points;
    
    void printSummary() const {
        std::cout << "=== WORKSPACE ANALYSIS ===" << std::endl;
        std::cout << "Robot trajectory bounds:" << std::endl;
        std::cout << "  Min: " << min_coords.transpose() << std::endl;
        std::cout << "  Max: " << max_coords.transpose() << std::endl;
        std::cout << "  Range: " << range.transpose() << std::endl;
        std::cout << "Total poses: " << total_poses << std::endl;
        std::cout << "Total points processed: " << total_points << std::endl;
    }
};

class DataAnalyzer {
public:
    static WorkspaceBounds analyzeDataset(const dataloader::Dataset& dataset, 
                                        bool include_sensor_points = true);
    static Eigen::Vector3d estimateOptimalOrigin(const WorkspaceBounds& bounds, 
                                               double safety_margin = 0.15);
    static std::array<size_t, 3> estimateGridDimensions(const WorkspaceBounds& bounds,
                                                       double resolution,
                                                       double safety_margin = 0.15);
};
