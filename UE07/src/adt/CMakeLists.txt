cmake_minimum_required(VERSION 3.14)
project(adt)

set(CMAKE_CXX_STANDARD 14)

add_executable(adt main.cpp graph_t.cpp vertex_t.cpp handle_t.cpp handle_t.h)