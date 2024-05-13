cmake_minimum_required(VERSION 3.14)  # Ensure FetchContent is available
project(lruBind)

include(FetchContent)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.6.1  # Optionally pin to a specific version
)
FetchContent_MakeAvailable(pybind11)

find_package(Python 3.8 COMPONENTS Interpreter Development REQUIRED)

# Buid Python module
pybind11_add_module(lruBind LRUBind.cpp)

# Include directories
target_include_directories(lruBind PRIVATE ../bin)

target_link_libraries(lruBind PRIVATE pybind11::pybind11 LRUCache)