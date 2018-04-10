cmake_minimum_required(VERSION 3.9)
project(PiggyBank1)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(PiggyBank1 main.cpp)