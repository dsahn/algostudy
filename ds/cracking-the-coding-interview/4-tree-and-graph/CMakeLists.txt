cmake_minimum_required (VERSION 2.6)
add_executable(1.out 1.cpp)
add_executable(2.out 2.cpp)
add_executable(3.out 3.cpp)
add_executable(4.out 4.cpp)

add_executable(bfs.out bfs.cpp)

add_definitions(-g -Wall)
set_property (TARGET 1.out PROPERTY CXX_STANDARD 11)
set_property (TARGET 2.out PROPERTY CXX_STANDARD 11)
set_property (TARGET 3.out PROPERTY CXX_STANDARD 11)
set_property (TARGET 4.out PROPERTY CXX_STANDARD 11)

set_property (TARGET bfs.out PROPERTY CXX_STANDARD 11)
