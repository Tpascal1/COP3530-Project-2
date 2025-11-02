cmake_minimum_required(VERSION 3.16)
project(Project_2 LANGUAGES CXX)

# Pick up all .cpp files in src/
file(GLOB SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(project2 ${SRC_FILES})
target_include_directories(project2 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(project2 PRIVATE cxx_std_17)

if (MSVC)
    target_compile_options(project2 PRIVATE /W4 /permissive-)
else()
    target_compile_options(project2 PRIVATE -Wall -Wextra -Wpedantic)
endif()


