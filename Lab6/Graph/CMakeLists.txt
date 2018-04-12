cmake_minimum_required(VERSION 3.9)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graph main.cpp edge.h graph.h graphadt.h node.h)