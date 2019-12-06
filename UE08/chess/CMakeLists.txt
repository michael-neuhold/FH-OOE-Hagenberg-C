cmake_minimum_required(VERSION 3.14)
project(chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(chess main.cpp chessman.cpp chessman.h chessboard.cpp chessboard.h types.h types.h king.cpp king.h io.cpp io.h)