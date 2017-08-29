cmake_minimum_required (VERSION 3.1)
project (unit_test_example)

find_package(Threads REQUIRED)

# Require c++11.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

##############
# External Library
##############

set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/external)
add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

enable_testing()

# Include the gtest library.
include_directories(
  ${gtest_SOURCE_DIR}/include
  ${gtest_SOURCE_DIR}
)

##############
# Executables
##############

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

##############
# Unit Tests
##############

set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)

target_link_libraries(${PROJECT_TEST_NAME}
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
    ${CMAKE_THREAD_LIBS_INIT}
    )

add_test(test1 ${PROJECT_TEST_NAME})
