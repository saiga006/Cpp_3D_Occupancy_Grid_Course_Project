cmake_minimum_required(VERSION 3.12)
project(occupancy_grid_3d) 

# find the dependent library packages, used apt-get install libopen3d-dev, sudo apt-get install libeigen3-dev
find_package(Open3D REQUIRED) 
find_package(Eigen3 REQUIRED)

# dataloader library to load pointclouds from Data/PLY folder
add_library(dataloader STATIC src/dataloader/dataloader.cpp)

target_compile_features(dataloader PRIVATE cxx_std_17)

target_compile_options(dataloader PRIVATE -Wall -Wextra)

target_include_directories(dataloader PUBLIC src/dataloader)

target_link_libraries(dataloader PUBLIC Open3D::Open3D Eigen3::Eigen)

# to visualise the pointclouds, as it consists no source files, use interface
add_library(visualizer INTERFACE)

target_include_directories(visualizer INTERFACE src/visualizer)

target_link_libraries(visualizer INTERFACE Open3D::Open3D Eigen3::Eigen)

#will have occupancy grid logic
add_executable(occupancy_grid_main src/main.cpp src/data_analyser.cpp)

target_link_libraries(occupancy_grid_main PRIVATE dataloader visualizer)

target_compile_options(occupancy_grid_main PRIVATE -Wall -Wextra)

target_compile_features(occupancy_grid_main PRIVATE cxx_std_17)