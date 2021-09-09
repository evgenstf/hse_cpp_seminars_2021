cmake_minimum_required(VERSION 2.8)
project(sample_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(AVERAGE_SOURCE average.cpp)
add_library(AVERAGE ${AVERAGE_SOURCE})

set(MAIN_SOURCE main.cpp)
add_executable(MAIN ${MAIN_SOURCE})

target_link_libraries(MAIN AVERAGE)
