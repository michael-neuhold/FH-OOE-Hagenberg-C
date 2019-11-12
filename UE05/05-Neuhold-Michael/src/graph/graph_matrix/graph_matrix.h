//
// Created by Michael Neuhold on 09.11.19.
//

#ifndef GRAPHS_GRAPH_MATRIX_H
#define GRAPHS_GRAPH_MATRIX_H

#include "./types.h"

void init_graph_m (graph_matrix *matrix);
void add_graph_node_m (graph_matrix *matrix, char *str);
void print_graph_nodes_m(graph_matrix matrix);
void add_edge_m (graph_matrix matrix, char  *origin_str, char  *target_str);
void remove_edge_m (graph_matrix  matrix, char *origin_str, char *target_str);
void remove_node_m (graph_matrix *matrix, char *str);

#endif //GRAPHS_GRAPH_MATRIX_H
