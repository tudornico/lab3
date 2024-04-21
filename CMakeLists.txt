cmake_minimum_required(VERSION 3.27)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 main.cpp ExtendedTest.cpp ExtendedTest.h Queue.cpp Queue.h
ShortTest.cpp ShortTest.h App.cpp
        MazeSolver.cpp
        MazeSolver.h)
