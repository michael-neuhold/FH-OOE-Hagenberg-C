//
// Created by Michael Neuhold on 08.11.19.
//

#ifndef UNTITLED_TYPES_H
#define UNTITLED_TYPES_H

/* ---------------------------------------------------------*/

typedef struct graph_list_node {
    char *payload;
    struct edge_node *edges;
    struct graph_list_node *next;
} graph_list_node;

typedef graph_list_node *graph_node_ptr;
typedef graph_node_ptr graph_list;

typedef struct edge_node {
    struct edge_node *next;
    struct graph_list_node *target;
} edge_node;

typedef edge_node *edge_node_ptr;

/* ---------------------------------------------------------*/

#endif //UNTITLED_TYPES_H
