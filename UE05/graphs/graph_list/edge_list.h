//
// Created by Michael Neuhold on 08.11.19.
//

#ifndef UNTITLED_EDGE_LIST_H
#define UNTITLED_EDGE_LIST_H

/* ---------------------------------------------------------*/

#include "./types.h"

/* ---------------------------------------------------------*/

edge_node_ptr new_edge_node(graph_node_ptr target);
void prepend_edge_node(edge_node_ptr *edge_list, edge_node_ptr n);
void print_edge_list(edge_node_ptr edge_list);
void remove_edge_list(edge_node_ptr *edge_list);

/* ---------------------------------------------------------*/

#endif //UNTITLED_EDGE_LIST_H
