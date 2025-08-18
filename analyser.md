## Build and Execution Output

```bash
saiga@sai-Ideapad:~/Downloads/ModernCppProject2025$ cmake --build build
Consolidate compiler generated dependencies of target dataloader
[ 40%] Built target dataloader
Consolidate compiler generated dependencies of target occupancy_grid_main
[ 60%] Building CXX object CMakeFiles/occupancy_grid_main.dir/src/main.cpp.o
[ 80%] Linking CXX executable occupancy_grid_main
[100%] Built target occupancy_grid_main
saiga@sai-Ideapad:~/Downloads/ModernCppProject2025$ cd build/
saiga@sai-Ideapad:~/Downloads/ModernCppProject2025/build$ ./occupancy_grid_main ../src/Data
Loading dataset...
Found 6770 scans

=== ANALYZING WORKSPACE ===
Analyzing 6770 poses...
Processed 0/6770 scans...
Processed 677/6770 scans...
Processed 1354/6770 scans...
Processed 2031/6770 scans...
Processed 2708/6770 scans...
Processed 3385/6770 scans...
Processed 4062/6770 scans...
Processed 4739/6770 scans...
Processed 5416/6770 scans...
Processed 6093/6770 scans...
=== WORKSPACE ANALYSIS ===
Robot trajectory bounds:
  Min: -135.352 -219.638 -7.10028
  Max: 141.576  124.18 40.7033
  Range: 276.928 343.819 47.8035
Total poses: 6770
Total points processed: 432690151
Dataset Analysis time: 443.096 seconds 

=== OPTIMAL GRID CONFIGURATION ===
Origin: -163.1 -254.1  -11.9
Dimensions: 3324×4126×574
Resolution: 0.1m (10cm voxels)
Total voxels: 7872308976
Estimated memory: 30030.5 MB
Grid covers: [-163.1 -254.1  -11.9] to [169.3 158.5  45.5]
WARNING: Large memory usage! Consider:
  - Increasing resolution (e.g., 0.2m instead of 0.1m)
  - Reducing safety margin
  - Processing subset of data first

=== APPLYING OPTIMIZATIONS ===
Auto-adjusted resolution to: 0.2m
Optimized memory usage: 2892.82 MB

=== OPTIMIZED GRID CONFIGURATION ===
Origin: -149.2 -236.9   -9.5
Dimensions: 1524×1892×263
Resolution: 0.2m (20cm per voxels)
Total voxels: 758336304
Estimated memory: 2892.82 MB
Grid covers: [-149.2 -236.9   -9.5] to [155.6 141.5  43.1]
OccupancyGrid3D initialized:
  Dimensions: 1524×1892×263
  Resolution: 0.2m
  Origin: -149.2 -236.9   -9.5
  Total voxels: 758336304
Grid creation time: 1.56853 seconds 

=== STARTING MAPPING ===
saiga@sai-Ideapad:~/Downloads/ModernCppProject2025/build$ cd ..
```

### Basic Functionality Test

```bash
saiga@sai-Ideapad:~/Downloads/ModernCppProject2025/build$ ./occupancy_grid_main 
=== TESTING BASIC FUNCTIONALITY ===
OccupancyGrid3D initialized:
  Dimensions: 50×50×25
  Resolution: 1m
  Origin: -25 -25   0
  Total voxels: 62500
Coordinate Conversion Test:
  World:  5.5 -3.2  2.8
  Grid: 30 21  2
  Back to World:  5.5 -3.5  2.5
  In Bounds: YES
  Occupancy after update: 0.85
  Occupancy after 5 updates: 5

=== BASIC FUNCTIONALITY TEST COMPLETED ===
```

### Run with Timing Stats

```bash
saiga@sai-Ideapad:~/Downloads/ModernCppProject2025/build$ ./occupancy_grid_main ../src/Data
Loading dataset...
Found 6770 scans

=== ANALYZING WORKSPACE ===
Analyzing 6770 poses...
Processed 0/6770 scans...
Processed 338/6770 scans...
Processed 676/6770 scans...
Processed 1014/6770 scans...
Processed 1352/6770 scans...
Processed 1690/6770 scans...
Processed 2028/6770 scans...
Processed 2366/6770 scans...
Processed 2704/6770 scans...
Processed 3042/6770 scans...
Processed 3380/6770 scans...
Processed 3718/6770 scans...
Processed 4056/6770 scans...
Processed 4394/6770 scans...
Processed 4732/6770 scans...
Processed 5070/6770 scans...
Processed 5408/6770 scans...
Processed 5746/6770 scans...
Processed 6084/6770 scans...
Processed 6422/6770 scans...
Processed 6760/6770 scans...
=== WORKSPACE ANALYSIS ===
Robot trajectory bounds:
  Min: -135.352 -219.638 -7.10028
  Max: 141.576  124.18 40.7033
  Range: 276.928 343.819 47.8035
Total poses: 6770
Total points processed: 432690151
Dataset Analysis time: 22.9543 seconds 

=== OPTIMAL GRID CONFIGURATION ===
Origin: -163.1 -254.1  -11.9
Dimensions: 3324×4126×574
Resolution: 0.1m (10cm voxels)
Total voxels: 7872308976
Estimated memory: 30030.5 MB
Grid covers: [-163.1 -254.1  -11.9] to [169.3 158.5  45.5]
WARNING: Large memory usage! Consider:
  - Increasing resolution (e.g., 0.2m instead of 0.1m)
  - Reducing safety margin
  - Processing subset of data first

=== APPLYING OPTIMIZATIONS ===
Auto-adjusted resolution to: 0.5m
Optimized memory usage: 148.276 MB

=== OPTIMIZED GRID CONFIGURATION ===
Origin: -138.2 -223.1   -7.6
Dimensions: 565×702×98
Resolution: 0.5m (50cm per voxels)
Total voxels: 38869740
Estimated memory: 148.276 MB
Grid covers: [-138.2 -223.1   -7.6] to [144.3 127.9  41.4]

=== STARTING MAPPING ===
OccupancyGrid3D initialized:
  Dimensions: 565×702×98
  Resolution: 0.5m
  Origin: -138.2 -223.1   -7.6
  Total voxels: 38869740
Grid creation time: 0.0459019 seconds 

=== PROCESSING LIDAR SCANS ===
Scan completed. Best rayTrace: 0.088 us, Worst rayTrace: 11.628 us
Mapped :: 0/6770 scans...
Scan completed. Best rayTrace: 0.099 us, Worst rayTrace: 13.404 us
Scan completed. Best rayTrace: 0.033 us, Worst rayTrace: 13.938 us
Scan completed. Best rayTrace: 0.034 us, Worst rayTrace: 13.828 us
Scan completed. Best rayTrace: 0.033 us, Worst rayTrace: 11.217 us
Scan completed. Best rayTrace: 0.035 us, Worst rayTrace: 13.52 us
Scan completed. Best rayTrace: 0.031 us, Worst rayTrace: 52.029 us
Scan completed. Best rayTrace: 0.031 us, Worst rayTrace: 16.557 us
Scan completed. Best rayTrace: 0.033 us, Worst rayTrace: 22.091 us
Scan completed. Best rayTrace: 0.055 us, Worst rayTrace: 137.093 us
Scan completed. Best rayTrace: 0.033 us, Worst rayTrace: 160.792 us
Scan completed. Best rayTrace: 0.033 us, Worst rayTrace: 173.393 us
Scan completed. Best rayTrace: 0.034 us, Worst rayTrace: 217.114 us
Scan completed. Best rayTrace: 0.034 us, Worst rayTrace: 405.679 us
Scan completed. Best rayTrace: 0.034 us, Worst rayTrace: 115.71 us
Scan completed. Best rayTrace: 0.034 us, Worst rayTrace: 155.032 us
Scan completed. Best rayTrace: 0.034 us, Worst rayTrace: 167.785 us
Mapped :: 677/6770 scans...
Mapping completed!
=== SCAN STATISTICS ===
Total scans processed: 678
Total execution time: 240.746 seconds
Best scan time: 0.0372507 seconds Worst scan time: 0.615129 seconds 
Average time per scan: 354.904 ms
Scan rate: 2.81624 scans/second
=== EXTRACTING OCCUPIED VOXELS ===
Extracted 40985 occupied voxels from 40985 tracked voxels (vs 38869740 total voxels)
Voxel extraction time: 0.00129689 seconds.
Visualising Voxels using open3D ===
Visualizing 40985 occupied voxels...
```

### Optimisation to reduce hash collision

```bash
Mapped :: 6093/6770 scans...
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.556 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.472 us
Scan completed. Best rayTrace: 0.065 us, Worst rayTrace: 14.765 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 24.717 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 19.241 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.939 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.055 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 20.078 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.267 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.473 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.903 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.75 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.901 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.15 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.739 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.006 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.668 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.939 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 33.342 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.907 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.609 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.905 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 19.214 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.406 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.414 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 21.969 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.05 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.787 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.843 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.097 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.576 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.49 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.462 us
Scan completed. Best rayTrace: 0.065 us, Worst rayTrace: 12.965 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.342 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.728 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.906 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.103 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.872 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.263 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 28.052 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.053 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.669 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.95 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.13 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.348 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.695 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 13.522 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.326 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.67 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.476 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.155 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.14 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.277 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.175 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.493 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 22.716 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.716 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.79 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.45 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 14.184 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.403 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.876 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.446 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.599 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.858 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.944 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.989 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 81.625 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 92.514 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.045 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.292 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 25.325 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.545 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.049 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.16 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.204 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.496 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.67 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.074 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.734 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.705 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.814 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 30.219 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.741 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.839 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.718 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.871 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.787 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.894 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.742 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.701 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.464 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.722 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.32 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 26.743 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.392 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.903 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 24.957 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 16.877 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 53.872 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.001 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.928 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.516 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.071 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.309 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.424 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.724 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.775 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.365 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.337 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.28 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.932 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 18.59 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.674 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.379 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.183 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.424 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.399 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 22.204 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 21.227 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.616 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.225 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 25.01 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 23.321 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.786 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.865 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.556 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.18 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 26.067 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.026 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.687 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 22.528 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.484 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.446 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.04 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.585 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.226 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 19.849 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.982 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.786 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 27.262 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.706 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.12 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.945 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.467 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.037 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 21.473 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.759 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.192 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.455 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 20.663 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.264 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.556 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.035 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.979 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.25 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.899 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.899 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.15 us
Scan completed. Best rayTrace: 0.065 us, Worst rayTrace: 74.365 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.453 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.536 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 23.415 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.252 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 15.087 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 21.214 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.901 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.706 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.452 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.282 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.539 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.235 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.375 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.901 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.032 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.782 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.688 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.519 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.084 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.28 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.28 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.758 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 23.702 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 21.951 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.057 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.195 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 22.912 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.471 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.007 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.553 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 16.954 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.704 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.174 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.966 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 15.735 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.509 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.539 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.902 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 20.563 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.178 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.726 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.346 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 27.654 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.821 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 15.778 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.327 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.978 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 28.548 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.671 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.087 us
Scan completed. Best rayTrace: 0.082 us, Worst rayTrace: 14.839 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.788 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 23.101 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 13.064 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.161 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.822 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.533 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.41 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.317 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.154 us
Scan completed. Best rayTrace: 0.072 us, Worst rayTrace: 17.381 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.554 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.071 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.328 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.25 us
Scan completed. Best rayTrace: 0.091 us, Worst rayTrace: 15.225 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.501 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.024 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.829 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.927 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.75 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.368 us
Scan completed. Best rayTrace: 0.087 us, Worst rayTrace: 13.831 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 22.662 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.193 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.693 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.823 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.098 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.558 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 17.725 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 14.018 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.022 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.818 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.422 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.937 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.37 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.632 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.113 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.293 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.561 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.691 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.896 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.935 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.618 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 26.878 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.411 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.189 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.993 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.713 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.411 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 27.721 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.292 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.305 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.687 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 23.478 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 23.024 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.684 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.676 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.954 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.182 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.443 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 31.549 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 26.372 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.109 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.379 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.868 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 13.842 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 11.889 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.196 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.733 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.114 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.242 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 21.653 us
Scan completed. Best rayTrace: 0.07 us, Worst rayTrace: 15.112 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.987 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 24.863 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.817 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 12.936 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.911 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 21.378 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.165 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.926 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.252 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.386 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.365 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.902 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.978 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 21.338 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.438 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.251 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.58 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 32.248 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.936 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.858 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.836 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.985 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.564 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 13.964 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.996 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.226 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 21.176 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.883 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.101 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.366 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 20.07 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.433 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.143 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.672 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.687 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.532 us
Scan completed. Best rayTrace: 0.147 us, Worst rayTrace: 15.067 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.401 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.68 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.814 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.051 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.054 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.665 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.932 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 25.946 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.402 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.909 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.87 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.242 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 21.146 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.609 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.401 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 19.601 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.181 us
Scan completed. Best rayTrace: 0.065 us, Worst rayTrace: 14.422 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.514 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.69 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.07 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 24.588 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.071 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.546 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.198 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.634 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.661 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.516 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 13.502 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.996 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.349 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.225 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.169 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.467 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.85 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 11.343 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 11.962 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 25.516 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 25.097 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.859 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.586 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.111 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.815 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.711 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.994 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.113 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.751 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.034 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.551 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 14.81 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.452 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 94.778 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.234 us
Scan completed. Best rayTrace: 0.143 us, Worst rayTrace: 13.357 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.37 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.118 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.063 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 21.382 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.574 us
Scan completed. Best rayTrace: 0.079 us, Worst rayTrace: 12.057 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.277 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 22.158 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 20.614 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.625 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.726 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.734 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.432 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 20.737 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 20.685 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.407 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.297 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.087 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.168 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.757 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.518 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.814 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 19.453 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.92 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.961 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 27.204 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.748 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.138 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.677 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 30.62 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.252 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.129 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.488 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.202 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.513 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.984 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.691 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.759 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 19.075 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.571 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.769 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.149 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.981 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.812 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.938 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.374 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.271 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.07 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.811 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.595 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.573 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.85 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.711 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.285 us
Scan completed. Best rayTrace: 0.142 us, Worst rayTrace: 14.369 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.954 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.196 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.254 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 12.119 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.697 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.64 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.207 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.999 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.173 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 15.66 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.109 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.781 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.116 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.195 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 17.109 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.575 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.36 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.622 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.486 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 23.55 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.889 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.602 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.698 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.17 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 24.419 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 22.193 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.29 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.237 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.303 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.286 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.026 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.485 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.299 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 21.536 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.237 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 19.561 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.663 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.344 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.307 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.299 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.648 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.867 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 28.882 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.062 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.109 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.674 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.277 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.111 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.589 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.629 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 19.814 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.902 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.221 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.659 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.2 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.812 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.412 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.774 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.096 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.746 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.539 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.704 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.157 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 19.82 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.403 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.186 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.795 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 20.079 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.858 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.942 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.903 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.215 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 15.259 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.692 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.681 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.57 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.605 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.356 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.886 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.419 us
Scan completed. Best rayTrace: 0.069 us, Worst rayTrace: 16.975 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 25.023 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.78 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.234 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.657 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.507 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.227 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.214 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.219 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.46 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.827 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.153 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.79 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 19.135 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.265 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.105 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.096 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 27.9 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.545 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.808 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.219 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.696 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 21.115 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.382 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 22.721 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.567 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 18.135 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.303 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.721 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.213 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.012 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.531 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.624 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.266 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.778 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.133 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 21.639 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.488 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.855 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 23.037 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.737 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.118 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.16 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.83 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 14.751 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.229 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.037 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.094 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.964 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.441 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 25.013 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.546 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.689 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.622 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.255 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.456 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 30.621 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.227 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.365 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.773 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.859 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.309 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.699 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.441 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.292 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.17 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.537 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.664 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.286 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.564 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.402 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.652 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.413 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.499 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.408 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.035 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.406 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 18.011 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.495 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.349 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.559 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.242 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.649 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.033 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.747 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.568 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.296 us
Scan completed. Best rayTrace: 0.066 us, Worst rayTrace: 15.249 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.543 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.237 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.237 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.724 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.449 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.855 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 18.21 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.794 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.632 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.309 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.955 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.306 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 16.445 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 25.856 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.666 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.726 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.711 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.668 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.758 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.286 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.241 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.086 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.049 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.459 us
Scan completed. Best rayTrace: 0.065 us, Worst rayTrace: 15.079 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 23.182 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.277 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.429 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.355 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.512 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.378 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.861 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.815 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.456 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.085 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.006 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.854 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.825 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.764 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 20.092 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.983 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.846 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.376 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.66 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.935 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.98 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 12.712 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.498 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.448 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.658 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 26.493 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 17.277 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 19.189 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.813 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.436 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.503 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 14.146 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 15.652 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.886 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 17.435 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.551 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.674 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 11.354 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.623 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.899 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 24.993 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.421 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.666 us
Scan completed. Best rayTrace: 0.068 us, Worst rayTrace: 13.467 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 16.866 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.128 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.89 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 13.781 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 15.181 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.276 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 12.72 us
Scan completed. Best rayTrace: 0.067 us, Worst rayTrace: 14.935 us
Mapping completed!
=== SCAN STATISTICS ===
Total scans processed: 6770
Total execution time: 277.43 seconds
Best scan time: 0.0172534 seconds Worst scan time: 0.0833583 seconds 
Average time per scan: 40.8301 ms
Scan rate: 24.4025 scans/second
=== EXTRACTING OCCUPIED VOXELS ===
Extracted 245669 occupied voxels from 245669 tracked voxels (vs 38869740 total voxels)
Voxel extraction time: 0.0204954 seconds.
Visualising Voxels using open3D ===
Visualizing 245669 occupied voxels...
Visualization time: 49.313 seconds.
````
