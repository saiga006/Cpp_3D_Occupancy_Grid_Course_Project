#pragma once

#include <Eigen/Core>
#include <array>
#include <vector>
#include <unordered_set>

using Vector3dVector = std::vector<Eigen::Vector3d>;
using Vector3d = Eigen::Vector3d;
using Vector3i = Eigen::Vector3i;
constexpr float OCCUPANCY_THRESHOLD = 0.5f;
 
class OccupancyGrid {
    private:
        std::array<size_t, 3> grid_dimensions;
        double voxel_resolution;
        // links grid coordinates with world coordinates
        Vector3d grid_origin;
        // has the occupancy grid probability data
        std::vector<float> grid_data;
        // Hash function for Vector3i
        struct Vector3iHash {
            size_t operator()(const Eigen::Vector3i& v) const {
                // Morton encoding for better spatial locality
                const size_t x = static_cast<size_t>(v.x());
                const size_t y = static_cast<size_t>(v.y());
                const size_t z = static_cast<size_t>(v.z());
                
                // FNV-1a hash variant optimized for integers
                size_t hash = 2166136261u;
                hash ^= x; hash *= 16777619u;
                hash ^= y; hash *= 16777619u;
                hash ^= z; hash *= 16777619u;
                return hash;
            }
        };

        struct Vector3iEqual {
            bool operator()(const Eigen::Vector3i& lhs, const Eigen::Vector3i& rhs) const {
                return lhs.x() == rhs.x() && lhs.y() == rhs.y() && lhs.z() == rhs.z();
            }
        };        
        // additional storage for fast lookup of occupied cells, would be updated as part of ray tracing
        std::unordered_set<Vector3i,Vector3iHash, Vector3iEqual> occupied_cells;

        // connects the start and end point of lidar ray in voxel map
        std::vector<Vector3i> draw_bresenham3d_line(const Vector3i& start, const Vector3i& end) const;
        // updates the log odds in the grid data for the voxel
        void update_occupied(const Vector3i& idx);
        void update_free(const Vector3i& idx);
        // check if the index within the grid boundary
        bool is_InBounds(const Vector3i& idx) const;
        // converts voxel index 3D to 1D index to fetch grid data when required.
        size_t to_LinearIndex(const Vector3i& idx) const;
    public:
        OccupancyGrid(const std::array<size_t, 3>& dimensions, double resolution, const Vector3d& origin);
        
        // implement transformations
        Vector3i world_to_grid(const Vector3d& world_coord) const;
        Vector3d grid_to_world(const Vector3i& grid_index) const;
        //for simple test
        float getOccupancy(const Vector3i& grid_index) const;

        // to update occupancy probability along the lidar scan
        void rayTrace(const Vector3d& start, const Vector3d& end);
        // to return the voxels which are occupied either by obstacles or grid boundary
        Vector3dVector getOccupiedVoxels(float threshold = 0.0f) const;
        //TODO: implement this logic - to detect if the lidar ray is crossing the grid boundary
        Vector3i findGridBoundaryIntersection(const Vector3i& start, const Vector3i& end) const;
        /* For simple occupancy unit testing code
        bool is_InBounds(const Vector3i& idx) const;
        void update_occupied(const Vector3i& idx);
        */
    };
