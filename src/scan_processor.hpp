#pragma once

#include "occupancy_grid.hpp"
#include "dataloader.hpp"

class ScanProcessor {
public:
    static void processLidarScan(OccupancyGrid& grid, const Eigen::Matrix4d& pose, 
                               const Vector3dVector& sensor_pointcloud);
};
