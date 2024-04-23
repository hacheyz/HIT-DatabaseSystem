cmake_minimum_required(VERSION 3.26)
project(QueryProcessing)

set(CMAKE_CXX_STANDARD 17)

add_executable(QueryProcessing main.cpp
        extmem.cpp
        extmem.h
        select.cpp
        select.h
        file.h
        blkio.cpp
        blkio.h
        project.cpp
        project.h
        join.h
        sortMergeJoin.cpp
        mergeSort.cpp
        mergeSort.h
        nestedLoopJoin.cpp
        hashJoin.cpp)
