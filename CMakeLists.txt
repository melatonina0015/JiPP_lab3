cmake_minimum_required( VERSION 3.0 )

project(JiPP_lab3)

include_directories( ./src ./include/JiPP_lab3 )

add_executable(test ./src/zad_1.cpp ./src/matrixclass.cpp)
