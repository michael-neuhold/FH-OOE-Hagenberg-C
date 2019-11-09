//
// Created by Michael Neuhold on 09.11.19.
//

#ifndef GRAPHS_GRAPH_LIST_H
#define GRAPHS_GRAPH_LIST_H


#if !defined GRAPH_LIST_H
#define      GRAPH_LIST_H

/* ---------------------------------------------------------*/

#include <stdbool.h>
#include "./types.h"

/* ---------------------------------------------------------*/

void init_graph_l (graph_list *list);
void add_graph_node_l (graph_list *list, char *str);
void print_graph_nodes_l (graph_node_ptr list);
void remove_node_l (graph_node_ptr *list, char *str);
void add_edge_l (graph_list list, char  *origin_str, char  *target_str);
void remove_all_edges_of_l (graph_list list, char *str);
void remove_edge_l (graph_list  list,char *origin_str, char *target_str);
void topological_sort_l(graph_list list);

/* ---------------------------------------------------------*/

graph_node_ptr new_node(char *str);
void prepend (graph_list *list, graph_node_ptr node);
bool node_exists(graph_list list, char *str);
bool edge_exists(graph_node_ptr origin, graph_node_ptr target);

/* ---------------------------------------------------------*/

#endif   // GRAPH_LIST_H


#endif //GRAPHS_GRAPH_LIST_H
