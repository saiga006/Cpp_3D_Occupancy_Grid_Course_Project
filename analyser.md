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
Visualization time: 54.764 seconds.
```
