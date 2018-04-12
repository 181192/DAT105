cmake_minimum_required(VERSION 3.10)
project(Exercise03)

set(CMAKE_CXX_STANDARD 14)

add_executable(Exercise03 main.cpp PriorityQueue.cpp PriorityQueue.h Enode.cpp Enode.h Edge.cpp Edge.h Node.h)