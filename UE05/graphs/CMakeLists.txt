cmake_minimum_required(VERSION 3.14)
project(graphs C)

set(CMAKE_C_STANDARD 11)

add_executable(graphs test.c test.h graph_list/graph_list.c graph_list/graph_list.h graph_list/types.h graph_list/edge_list.c graph_list/edge_list.h io_lib.c io_lib.h graph_matrix/graph_matrix.c graph_matrix/graph_matrix.h graph_matrix/types.h)