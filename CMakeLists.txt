cmake_minimum_required(VERSION 3.20)
project(AVS_HW5)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVS_HW5 src/main.cpp src/Visitor/visitor.cpp src/Visitor/visitor.h src/Painting/Painting.cpp src/Painting/Painting.h)
