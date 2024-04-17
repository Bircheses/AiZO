cmake_minimum_required(VERSION 3.27)
project(Aizo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Aizo
        MainMenu.cpp
        Sources/Sort.cpp
        Sources/Sort.h
        Sources/InsertionSort.cpp
        Sources/InsertionSort.h
        Sources/Counter.cpp
        Sources/Counter.h
        Sources/QuickSort.cpp
        Sources/QuickSort.h
        Sources/ShellSort.cpp
        Sources/ShellSort.h
        Sources/HeapSort.cpp
        Sources/HeapSort.h
        StaticFunctions.cpp
)
