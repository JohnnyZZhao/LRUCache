# MyLibrary/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(LRUCache)

# Create a shared library
add_library(LRUCache SHARED LRU.cpp)

# Specify interface directories
target_include_directories(LRUCache PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
