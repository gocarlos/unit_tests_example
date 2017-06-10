cmake_minimum_required (VERSION 2.8)
project (unit_test_example)

# Use C++11 : cmake >= 3.1
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use C++11 : cmake <= 3.1
add_definitions(-std=c++11)

##############
# External Library
##############

# TODO(gocarlos) add this as an external project.
add_subdirectory(lib/googletest-1.8.0)

enable_testing()

# Include the gtest library.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

##############
# Executables
##############

add_executable (main src/sorting_and_searching.cpp)

##############
# Unit Tests
##############

add_executable(unit_test gtest/sorting_and_searching_test.cpp)
target_link_libraries(unit_test gtest gtest_main)
