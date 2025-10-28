cmake_minimum_required(VERSION 3.31)
project(Project_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project_2
        src/Songs.cpp
        include/Songs.h
        src/SortHeap.cpp
        include/SortHeap.h
        include/io.h
        src/io.cpp)
