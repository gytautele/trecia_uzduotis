cmake_minimum_required(VERSION 3.13)
project(penkta_su_headeriais)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")

add_executable(penkta_su_headeriais main.cpp circle.h circle.cpp)
