cmake_minimum_required(VERSION 3.27)
project(Aizo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Aizo
        MainMenu.cpp
        Sources/Sort.cpp
        Sources/Sort.h
        Sources/InsertionSort.cpp
        Sources/InsertionSort.h
        Counter.cpp
        Counter.h
        Sources/QuickSort.cpp
        Sources/QuickSort.h
        Sources/ShellSort.cpp
        Sources/ShellSort.h)
