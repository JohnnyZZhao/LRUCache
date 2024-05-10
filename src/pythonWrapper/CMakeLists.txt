cmake_minimum_required(VERSION 3.14)  # Ensure FetchContent is available
project(lruWrapper)

include(FetchContent)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.6.1  # Optionally pin to a specific version
)
FetchContent_MakeAvailable(pybind11)

find_package(Python 3.11 COMPONENTS Interpreter Development REQUIRED)

# Buid Python module
pybind11_add_module(lruWrapper LRUWrapper.cpp)

# Include directories
target_include_directories(lruWrapper PRIVATE ../bin)

target_link_libraries(lruWrapper PRIVATE pybind11::pybind11 LRUCache)