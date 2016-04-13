cmake_minimum_required(VERSION 3.3)
project(Algos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp test.v)
add_executable(Algos ${SOURCE_FILES})