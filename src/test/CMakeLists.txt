cmake_minimum_required(VERSION 3.14)

project(LRU_Test)

CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  VERSION 1.14.0
  OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt"
)

enable_testing()

# Add executable
add_executable(LRU_Test LRU_test.cpp)

# Include directories
target_include_directories(LRU_Test PRIVATE ../bin)

# Link the library
target_link_libraries(LRU_Test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(LRU_Test)