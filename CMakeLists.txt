cmake_minimum_required(VERSION 3.27)
project(lab3)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-DDEFINITION 1)
add_library(queue1 Queue.h Queue.cpp )
add_executable( lab3 App.cpp
        MazeSolver.cpp
        MazeSolver.h
        )
link_libraries(lab3 queue1)


add_executable( test TestMain.cpp ExtendedTest.cpp ExtendedTest.h
        ShortTest.cpp ShortTest.h )


