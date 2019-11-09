//
// Created by Michael Neuhold on 09.11.19.
//


/* ---------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include "./edge_list.h"

/* ---------------------------------------------------------*/

edge_node_ptr new_edge_node(graph_node_ptr target) {
    edge_node_ptr n = malloc(sizeof(edge_node));
    n -> target = target;
    n -> next = NULL;
    return n;
}

/* ---------------------------------------------------------*/

void prepend_edge_node(edge_node_ptr *edge_list, edge_node_ptr n) {
    n -> next = *edge_list;
    *edge_list = n;
}

/* ---------------------------------------------------------*/

void print_edge_list(edge_node_ptr edge_list) {
    edge_node_ptr l = edge_list;
    while(l != NULL) {
        graph_node_ptr n = l -> target;
        printf("# %s ", n -> payload );
        l = l -> next;
    }
}

/* ---------------------------------------------------------*/

void remove_edge_list(edge_node_ptr *edge_list) {
    edge_node_ptr n;
    while(*edge_list != NULL) {
        n = *edge_list;
        (*edge_list) = (*edge_list) -> next;
        free(n);
    }
}
