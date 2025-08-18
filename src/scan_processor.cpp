#include "scan_processor.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>

void ScanProcessor::processLidarScan(OccupancyGrid& grid, const Eigen::Matrix4d& pose, 
                                     const Vector3dVector& sensor_pointcloud) {
    // Extract sensor position from pose
    const Vector3d sensor_position = pose.block<3,1>(0,3);
    // Extract rotation matrix from pose
    const Eigen::Matrix3d rotation = pose.block<3,3>(0,0);

    double min_time = std::numeric_limits<double>::max();
    double max_time = 0.0;

    // Transform each point and trace ray
    std::for_each(sensor_pointcloud.begin(),sensor_pointcloud.end(),[&](const Vector3d& sensor_point) {
        // transform sensor values from sensor frame to world frame
        Vector3d world_position = rotation * sensor_point + sensor_position;
        
        // Trace ray from sensor to point
        auto start_time = std::chrono::high_resolution_clock::now();
        grid.rayTrace(sensor_position, world_position);
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> elapsed_time = end_time - start_time;
        
        if (elapsed_time.count() < min_time) {
            min_time = elapsed_time.count();
        }
        if (elapsed_time.count() > max_time) {
            max_time = elapsed_time.count();
        }
    });

    /* Enable only for debugging
    std::cout << "Scan completed. Best rayTrace: " << min_time 
              << " us, Worst rayTrace: " << max_time << " us\n";
              */
}
