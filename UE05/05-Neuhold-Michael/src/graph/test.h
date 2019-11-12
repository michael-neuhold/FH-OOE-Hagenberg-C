//
// Created by Michael Neuhold on 09.11.19.
//

#ifndef GRAPHS_TEST_H
#define GRAPHS_TEST_H

//#define GRAPH_LIST

#ifdef GRAPH_LIST

/* ---------------------------------------------------------*/

#include "./graph_list/graph_list.h"
typedef graph_list graph;
#define graph_init init_graph_l
#define graph_add_node add_graph_node_l
#define graph_print print_graph_nodes_l
#define graph_add_edge add_edge_l
#define graph_remove_all_edges_from_node remove_all_edges_of_l
#define graph_remove_edge remove_edge_l
#define graph_remove_node remove_node_l
#define graph_topological_sort topological_sort_l
/* ---------------------------------------------------------*/

#else

/* ---------------------------------------------------------*/
#include "./graph_matrix/graph_matrix.h"
typedef graph_matrix graph;
#define graph_init init_graph_m
#define graph_add_node add_graph_node_m
#define graph_print print_graph_nodes_m
#define graph_add_edge add_edge_m
#define graph_remove_all_edges_from_node remove_all_edges_of_m
#define graph_remove_edge remove_edge_m
#define graph_remove_node remove_node_m
/* ---------------------------------------------------------*/

#endif

#endif //GRAPHS_TEST_H
