cmake_minimum_required(VERSION 3.0)

project(v.1.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}\\headers)

add_executable(obj_deque final.v.1.0.deque.cpp)
add_executable(obj_list final.v.1.0.list.cpp)
add_executable(obj_vector final.v.1.0.vector.cpp)
