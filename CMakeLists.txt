cmake_minimum_required(VERSION 3.27)
project(lab3)

set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(DEFINITION=1)



add_executable(lab3 App.cpp MazeSolver.cpp MazeSolver.h Queue.h Queue.cpp)
target_compile_definitions(lab3 PRIVATE DEFINITION=1)

add_executable(test TestMain.cpp ExtendedTest.cpp ExtendedTest.h ShortTest.cpp ShortTest.h Queue.h Queue.cpp)
target_compile_definitions(test PRIVATE DEFINITION=2)