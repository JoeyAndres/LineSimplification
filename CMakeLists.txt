cmake_minimum_required(VERSION 2.8)
project(douglas_peucker)

enable_testing()

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g")

add_subdirectory(src)
add_subdirectory(test)
