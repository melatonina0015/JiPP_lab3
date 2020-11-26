cmake_minimum_required( VERSION 3.0 )

project(Lab_3)

include_directories( ./src ./include/Lab_3 )

add_executable(test ./src/zad_1.cpp ./src/matrixclass.cpp)
