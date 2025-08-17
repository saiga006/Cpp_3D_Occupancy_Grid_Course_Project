#include "occupancy_grid.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>


// Log-odds constants
constexpr float LOG_ODDS_OCCUPIED = 0.85f;
constexpr float LOG_ODDS_FREE = -0.4f;
constexpr float LOG_ODDS_MIN = -5.0f;
constexpr float LOG_ODDS_MAX = 5.0f;

OccupancyGrid::OccupancyGrid(const std::array<size_t, 3>& dimensions, 
    double resolution, const Vector3d& origin)
    :grid_dimensions(dimensions), voxel_resolution(resolution), grid_origin(origin) {

    size_t total_cells = grid_dimensions[0] * grid_dimensions[1] * grid_dimensions[2];
    grid_data.resize(total_cells,0.0f);
    
    std::cout << "OccupancyGrid3D initialized:" << std::endl;
    std::cout << "  Dimensions: " << grid_dimensions[0] << "×" << grid_dimensions[1] << "×" << grid_dimensions[2] << std::endl;
    std::cout << "  Resolution: " << voxel_resolution << "m" << std::endl;
    std::cout << "  Origin: " << grid_origin.transpose() << std::endl;
    std::cout << "  Total voxels: " << total_cells << std::endl;

}

// converts world coordinates to grid coordinates, assuming grid origin starts in bottom left corner of the map.
Vector3i OccupancyGrid::world_to_grid(const Vector3d& world_coord) const {
    Vector3d diff = world_coord - grid_origin;
    return Vector3i(
        static_cast<int>(std::floor(diff.x()/voxel_resolution)),
        static_cast<int>(std::floor(diff.y()/voxel_resolution)),
        static_cast<int>(std::floor(diff.z()/voxel_resolution))
    );
}

// converts grid coordinates to world coordinates 
Vector3d OccupancyGrid::grid_to_world(const Vector3i& grid_index) const {
    return grid_origin + Vector3d((grid_index.x() + 0.5) * voxel_resolution,
                                (grid_index.y() + 0.5) * voxel_resolution,
                                (grid_index.z() + 0.5) * voxel_resolution);
}

// check if the index is valid and within the grid dimensions
bool OccupancyGrid::is_InBounds(const Vector3i& idx) const {
    return idx.x() >= 0 && idx.x() < static_cast<int>(grid_dimensions[0]) &&
           idx.y() >= 0 && idx.y() < static_cast<int>(grid_dimensions[1]) &&
           idx.z() >= 0 && idx.z() < static_cast<int>(grid_dimensions[2]);
}

//converts 3d grid coordinates to 1d index.
size_t OccupancyGrid::to_LinearIndex(const Vector3i& idx) const {
    return static_cast<size_t>(idx.z()) * grid_dimensions[0] * grid_dimensions[1] +
           static_cast<size_t>(idx.y()) * grid_dimensions[0] +
           static_cast<size_t>(idx.x());
}

// updates occupancy
void OccupancyGrid::update_occupied(const Vector3i& idx) {
    if(!is_InBounds(idx)) return;
    size_t index = to_LinearIndex(idx);
    grid_data[index] = std::clamp(grid_data[index]+ LOG_ODDS_OCCUPIED,
         LOG_ODDS_MIN, LOG_ODDS_MAX);
}

// updates occupancy
void OccupancyGrid::update_free(const Vector3i& idx) {
    if(!is_InBounds(idx)) return;
    size_t index = to_LinearIndex(idx);
    grid_data[index] = std::clamp(grid_data[index]+ LOG_ODDS_FREE,
         LOG_ODDS_MIN, LOG_ODDS_MAX);
}

// Simple getOccupancy for testing
float OccupancyGrid::getOccupancy(const Vector3i& grid_index) const {
    if (!is_InBounds(grid_index)) return 0.0f;
    return grid_data[to_LinearIndex(grid_index)];
}

// PLACEHOLDER FUNCTIONS - IMPLEMENT
std::vector<Vector3i> OccupancyGrid::draw_bresenham3d_line(const Vector3i& start, const Vector3i& end) const {
    // TODO: Implement 3D Bresenham algorithm
    // PRIORITY: CRITICAL - Core mapping algorithm
    std::vector<Vector3i> voxels;
    voxels.push_back(start);
    voxels.push_back(end);  // Temporary placeholder
    return voxels;
}

void OccupancyGrid::rayTrace(const Vector3d& start, const Vector3d& end) {
    // TODO: Implement ray tracing
    // PRIORITY: CRITICAL - Main occupancy update method
    Vector3i start_grid = world_to_grid(start);
    Vector3i end_grid = world_to_grid(end);
    
    if (is_InBounds(start_grid) && is_InBounds(end_grid)) {
        update_occupied(end_grid);  // Temporary: just mark endpoint
    }
}

Vector3dVector OccupancyGrid::getOccupiedVoxels(float threshold) const {
    // TODO: Implement visualization extraction
    // PRIORITY: HIGH - Needed for final visualization
    Vector3dVector occupied_points;
    return occupied_points;
}
