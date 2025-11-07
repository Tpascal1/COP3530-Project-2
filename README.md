# Song Artist Rank Based on Hotness

## Overview
This project loads and sorts a large dataset from CORGIS using both a Heapsort and Mergesort implementation. The program then will run and compare the runtime of each algorithm and determine whic is faster.

## Build Instructions (Windows / MSVC)
Good to Have:
- Visual Studio (with C++ Build Tools)
- CMake (v3.16+)
- SFML 2.5.1 (also in resources folder)

## Steps:
```bash
# From the project root directory
rmdir /s /q build
mkdir build
cd build

# Generate build files with CMake
cmake -G "NMake Makefiles" ..

# Build executablpe 
cmake --build .

#Run
.\project2.exe