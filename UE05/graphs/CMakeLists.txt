cmake_minimum_required(VERSION 3.14)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled test.c graph_includer.h graph_selector.h graph_list/graph_list.h graph_list/graph_list.c graph_matrix/graph_matrix.h graph_matrix/graph_matrix.c graph_list/edge_list.h graph_list/edge_list.c graph_list/types.h)