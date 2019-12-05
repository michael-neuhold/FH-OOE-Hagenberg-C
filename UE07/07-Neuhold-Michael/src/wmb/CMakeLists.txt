cmake_minimum_required(VERSION 3.14)
project(adt)

set(CMAKE_CXX_STANDARD 14)

add_executable(adt main.cpp car.cpp car.h engine.cpp engine.h tire.cpp tire.h main.h)