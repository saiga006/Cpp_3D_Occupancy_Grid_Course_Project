# 3D Occupancy Grid Mapping from LiDAR Scans

This is a C++ Uni Bonn course project for SoSe 25, which demonstrates the creation of a 3D occupancy grid map from a series of LiDAR scans and vehicle poses. It leverages modern C++17 features, the Eigen library for efficient linear algebra, and the Open3D library for visualization.

The application processes a dataset of point clouds, determines the optimal grid size and resolution, and then integrates each scan to build a map of the environment, distinguishing between free and occupied space.

## Project Overview

The core of the project is to build a probabilistic 3D map of an environment. This is achieved by:

1. **Analyzing the entire dataset** to calculate the necessary bounds for the world, ensuring the grid is large enough to contain the entire trajectory.
2. **Creating an optimal 3D grid** with a specified resolution. The implementation includes safeguards and auto-adjustments for memory-intensive configurations.
3. **Processing each LiDAR scan**: For each point in a scan, a ray is cast from the sensor origin to the point.
4. **Updating Voxel Occupancy**: Voxels along the ray are marked as "free," and the voxel at the ray's endpoint is marked as "occupied" using a log-odds probability model.
5. **Visualizing the Result**: The final set of occupied voxels is extracted and rendered as a 3D point cloud.

## Code Structure

The project is organized into several components to separate concerns:

-   `src/main.cpp`: The main entry point of the application. It orchestrates the entire workflow, from data loading and analysis to mapping and visualization.
-   `src/dataloader/`: A static library responsible for loading LiDAR point cloud data (`.ply` files) and the corresponding ground truth poses.
-   `src/data_analyser.cpp/.hpp`: Contains the logic to perform an initial pass over the entire dataset to determine the environment's boundaries, which is used to configure the optimal grid size and resolution.
-   `src/scan_processor.cpp/.hpp`: Handles the processing of individual LiDAR scans, transforming points to the world frame and integrating them into the occupancy grid.
-   `src/occupancy_grid.cpp/.hpp`: Implements the core 3D occupancy grid data structure, including voxel management, coordinate transformations, the log-odds update model, and the 3D Bresenham's algorithm for ray tracing.
-   `src/visualizer/`: An interface library that provides a simple wrapper around Open3D for visualizing the final grid of occupied voxels.

## Features

- **Dynamic Grid Sizing**: Automatically analyzes the dataset to determine optimal grid dimensions and origin.
- **Memory Management**: Includes warnings and automatic resolution adjustments for potentially large grid sizes.
- **Efficient Ray Tracing**: Implements a 3D Bresenham's line algorithm for ray casting.
- **Probabilistic Mapping**: Uses log-odds values to update voxel states, making the map robust to sensor noise.
- **Performance Optimized**: Written with modern C++ and performance in mind, leveraging stl algos, efficient stl containers, and release build optimizations.
- **3D Visualization**: Uses Open3D to render the final occupancy grid.

## Dependencies

- **Eigen3**: For matrix and vector operations.
- **Open3D**: For point cloud processing and visualization.

You can install the dependencies on a Debian-based system using:

```bash
sudo apt-get install libeigen3-dev libopen3d-dev
```

## Compilation

The project uses CMake. To compile, run the following commands from the project's root directory:

```bash
# Configure the project for a Release build
cmake -DCMAKE_BUILD_TYPE=Release -Bbuild -S.

# Build the project using 24 parallel jobs
cmake --build build -j 24
```

The executable will be located at `build/occupancy_grid_main`.

### Compiler Optimizations

For `Release` builds, the following compiler flags are enabled in `CMakeLists.txt` to maximize performance:
-   `-O3`: Enables the highest level of compiler optimization.
-   `-DNDEBUG`: Disables `assert()` calls to avoid runtime checks.
-   `-march=native`: Instructs the compiler to generate code specifically optimized for the CPU architecture of the machine it's being compiled on.
-   `-ffast-math`: Allows for more aggressive floating-point optimizations that may not be strictly IEEE-compliant but are faster.
-   `-funroll-loops`: Unrolls loops to reduce branch overhead, which can improve performance for tight loops.

## Execution

To run the application, provide the path to the data directory from the `build` directory:

```bash
./occupancy_grid_main ../src/Data
```

## Results

The following images show the final 3D occupancy grid generated from the full dataset, viewed from different angles.

**Top-Down View:**
![Top-Down View of the Occupancy Grid](images/3d_occupancy_grid_top_view.png)

**Side View:**
![Side View of the Occupancy Grid](images/3d_occupancy_grid_side_view.png)

**Inside View:**
![Inside View of the Occupancy Grid](images/3d_occupancy_grid_inside_view.png)

### Performance Statistics

The following statistics were recorded after processing the entire dataset of 6770 scans. The grid was configured with the following parameters:

- **Dataset Range (X, Y, Z)**: 276.9m, 343.8m, 47.8m
- **Grid Coverage**: From [-138.2, -223.1, -7.6] to [144.3, 127.9, 41.4]
- **Grid Origin**: -138.2, -223.1, -7.6
- **Grid Resolution**: 0.5m (50cm per voxel)
- **Grid Dimensions**: 565 x 702 x 98
- **Total Voxels**: 38,869,740

Performance results with the hash collision optimization enabled:

- **Total Scans Processed**: 6770
- **Total Execution Time**: 277.43 seconds
- **Average Time per Scan**: 40.83 ms
- **Scan Rate**: 24.4 scans/second
- **Final Occupied Voxels**: 245,669
- **Voxel Extraction Time**: 0.02 seconds

## Project Assignment

The detailed requirements and goals for this project are outlined in the official course assignment document.

[View Project Assignment](./project_assignment.pdf)

## References

This project was developed with the help of the following educational resources:

-   **Bresenham's Line Algorithm Visualization**: A clear visual explanation of the 2D Bresenham's algorithm, which forms the basis for the 3D implementation in this project. [Watch on YouTube](https://youtu.be/8gIhNSAXYcQ).
-   **Bresenham's Line Algorithm Coding Tutorial**: A coding tutorial for a 2D implementation of Bresenham's algorithm that was adapted to 3D for this project. [Watch on YouTube](https://youtu.be/CceepU1vIKo).
-   **SLAM Lecture on Occupancy Grid Mapping**: A comprehensive lecture covering the theory behind occupancy grid maps, including the log-odds representation, inverse sensor models, and the static binary Bayes filter, all of which are fundamental concepts for this project. [Watch on YouTube](https://youtu.be/v-Rm9TUG9LA).

