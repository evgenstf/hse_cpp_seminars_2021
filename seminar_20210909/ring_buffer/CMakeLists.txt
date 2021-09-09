cmake_minimum_required(VERSION 2.8)
project(ring_buffer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(RING_BUFFER_SOURCE ring_buffer.cpp)
add_library(RING_BUFFER ${RING_BUFFER_SOURCE})

add_executable(MAIN main.cpp)


target_link_libraries(MAIN RING_BUFFER)



# Setup testing
link_directories(/usr/local/lib)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_custom_target(tests COMMAND GTEST_COLOR=yes ${CMAKE_CTEST_COMMAND} --verbose)

file(GLOB TEST_FILES "tests/*.cpp")
add_executable("ring_buffer_tests" EXCLUDE_FROM_ALL ${TEST_FILES})
target_link_libraries("ring_buffer_tests" gtest pthread RING_BUFFER)
add_dependencies(tests "ring_buffer_tests")
add_test("ring_buffer_tests" "./ring_buffer_tests")
