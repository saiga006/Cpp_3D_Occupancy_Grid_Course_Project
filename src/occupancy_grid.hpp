#pragma once

#include <Eigen/Core>
#include <array>
#include <vector>

using Vector3dVector = std::vector<Eigen::Vector3d>;
using Vector3d = Eigen::Vector3d;
using Vector3i = Eigen::Vector3i;

//TODO: implement the member functions 
class OccupancyGrid {
    private:
        std::array<size_t, 3> voxel_dimensions;
        double voxel_resolution;
        // links grid coordinates with world coordinates
        Vector3d grid_origin;
        std::vector<float> grid_data;
        // connects the start and end point of lidar ray in voxel map
        std::vector<Vector3i> draw_bresenham3d_line(const Vector3i& start, const Vector3i& end) const;
        // updates the log odds aka grid data for the voxel
        void update_occupied(const Vector3i& idx);
        void update_free(const Vector3i& idx);
        // check if the index within the grid boundary
        bool is_InBounds(const Vector3i& idx) const;
        // converts voxel index 3D to 1D index to fetch grid data when required.
        size_t to_LinearIndex(const Vector3i& idx) const;
    public:
        OccupancyGrid(const std::array<size_t, 3>& dimensions, double resolution, const Vector3d& origin);
        
        // TODO: implement transformations
        Vector3i world_to_grid(const Vector3d& world_coord) const;
        Vector3d grid_to_world(const Vector3i& grid_index) const;
        // to update occupancy probability along the lidar scan
        void rayTrace(const Vector3d& start, const Vector3d& end);
        // to return the voxels which are occupied either by obstacles or grid boundary
        Vector3dVector getOccupiedVoxels(float threshold = 0.0f) const;
        //to detect if the lidar ray is crossing the grid boundary
        Vector3i findGridBoundaryIntersection(const Vector3i& start, const Vector3i& end) const;
};



// namespace dataloader
// {
//     class Dataset
//     {
//     public:
//         Dataset(const std::string &data_dir);
//         std::size_t size() const { return pointcloud_files_.size(); }
//         PoseAndCloud operator[](const int idx) const;

//     private:
//         std::vector<std::string> pointcloud_files_;
//         std::vector<Eigen::Matrix4d> poses_;
//     };
// } // namespace dataloader
