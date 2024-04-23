cmake_minimum_required(VERSION 3.26)
project(QueryOptimize)

set(CMAKE_CXX_STANDARD 17)

add_executable(QueryOptimize main.cpp
        tree.cpp
        tree.h)
