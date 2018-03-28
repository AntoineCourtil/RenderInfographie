cmake_minimum_required(VERSION 3.9)
project(Infographie)

set(CMAKE_CXX_STANDARD 98)

add_executable(Infographie main.cpp image/tgaimage.cpp geometry/line.cpp geometry/line.h geometry/triangle.cpp geometry/triangle.h geometry/Point2D.cpp geometry/Point2D.h image/objfile.cpp image/objfile.h geometry/Point3D.cpp geometry/Point3D.h image/objmodel.cpp image/objmodel.h)