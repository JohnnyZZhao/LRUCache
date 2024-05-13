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


# Option to enable unit tests
option(ENABLE_UT "Enable unit tests" OFF)

if(ENABLE_UT)
    # download CPM.cmake
    file(
    DOWNLOAD
    https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
    EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
    )
    include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

    add_subdirectory(src/test)
endif()

if(ENABLE_PYTHON)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

add_subdirectory(src/pythonBind)
endif()