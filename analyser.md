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

=== OPTIMAL GRID CONFIGURATION ===
Origin: -163.1 -254.1  -11.9
Dimensions: 3324×4126×574
Resolution: 0.1m (10cm voxels)
Total voxels: 7872308976
Estimated memory: 30030.5 MB
Grid covers: [-163.1 -254.1  -11.9] to [169.3 158.5  45.5]
WARNING: Large memory usage! Consider:
  - Increasing resolution (e.g., 0.5m instead of 0.2m)
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

=== STARTING MAPPING ===
saiga@sai-Ideapad:~/Downloads/ModernCppProject2025/build$ cd ..
```
