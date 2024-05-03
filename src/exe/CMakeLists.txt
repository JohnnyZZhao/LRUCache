# MyApp/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(LRUCacheApp)

# Add executable
add_executable(LRUCacheApp main.cpp)

# Include directories
target_include_directories(LRUCacheApp PRIVATE ../bin)

# Link the library
target_link_libraries(LRUCacheApp PRIVATE LRUCache)
