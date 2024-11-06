cmake_minimum_required(VERSION 3.10)
project(Grafs)

set(CMAKE_CXX_STANDARD 17)

add_executable(adjacenty_matrix old_grafs/adjacenty_matrix.cpp)
add_executable(adjacenty_list old_grafs/adjacenty_list.cpp)
add_executable(new_adjacenty_list new_grafs/new_adjacenty_list.cpp)