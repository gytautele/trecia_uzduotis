cmake_minimum_required(VERSION 3.13)
project(v1_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")

add_executable(v1_1 main.cpp classes/generavimas.cpp classes/timer.cpp classes/function.cpp headers/main_header.h headers/time.h)