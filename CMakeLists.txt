# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Define the project name and version
project(LRUproject VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(src/bin)
add_subdirectory(src/exe)
