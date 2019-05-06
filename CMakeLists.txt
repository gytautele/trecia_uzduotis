cmake_minimum_required(VERSION 3.13)
project(v1_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")

add_executable(v1_1 main.cpp generavimas.cpp function.cpp timer.cpp main_header.h time.h)