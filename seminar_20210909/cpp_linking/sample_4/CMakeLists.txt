cmake_minimum_required(VERSION 2.8)
project(sample_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(AVERAGE_SOURCE average.cpp)
add_library(AVERAGE average.cpp)

set(MAIN_SOURCE main.cpp)
add_executable(MAIN main.cpp)

target_link_libraries(MAIN AVERAGE)

