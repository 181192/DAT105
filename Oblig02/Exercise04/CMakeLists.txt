cmake_minimum_required(VERSION 3.10)
project(Exercise04)

set(CMAKE_CXX_STANDARD 14)

add_executable(Exercise04 main.cpp Graph.h GraphADT.h ../Exercise03/Node.h ../Exercise03/Enode.cpp ../Exercise03/Enode.cpp ../Exercise03/Edge.h ../Exercise03/Edge.cpp ../Exercise03/PriorityQueue.h ../Exercise03/PriorityQueue.cpp)