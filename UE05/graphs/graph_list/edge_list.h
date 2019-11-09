//
// Created by Michael Neuhold on 09.11.19.
//

#ifndef GRAPHS_EDGE_LIST_H
#define GRAPHS_EDGE_LIST_H

/* ---------------------------------------------------------*/

#include "./types.h"

/* ---------------------------------------------------------*/

edge_node_ptr new_edge_node(graph_node_ptr target);
void prepend_edge_node(edge_node_ptr *edge_list, edge_node_ptr n);
void print_edge_list(edge_node_ptr edge_list);
void remove_edge_list(edge_node_ptr *edge_list);

/* ---------------------------------------------------------*/

#endif //GRAPHS_EDGE_LIST_H
