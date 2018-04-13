cmake_minimum_required(VERSION 3.10)
project(Exercise01)

set(CMAKE_CXX_STANDARD 14)

add_executable(Exercise01 main.cpp IteratorADT.h VectorImpl.h ListImpl.h IteratorImpl.h)