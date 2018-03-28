cmake_minimum_required(VERSION 3.9)
project(Infographie)

set(CMAKE_CXX_STANDARD 98)

add_executable(Infographie main.cpp tgaimage.cpp geometry/line.cpp geometry/line.h geometry/triangle.cpp geometry/triangle.h)