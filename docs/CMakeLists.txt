cmake_minimum_required(VERSION 3.31)
project(Project_2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Project_2
        src/Songs.cpp
        src/SortHeap.cpp
        src/io.cpp
        src/main.cpp
        src/SortMerge.cpp
)
