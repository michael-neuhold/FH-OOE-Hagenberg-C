//
// Created by Michael Neuhold on 09.11.19.
//

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./graph_matrix.h"

#define SIZE_BEGIN 7

/* ---------------------------------------------------------*/

void init_graph_m (graph_matrix *matrix) {
    matrix -> elm = 0;
    matrix -> edges = (bool*)malloc(sizeof(bool) * (SIZE_BEGIN * SIZE_BEGIN));
    matrix -> nodes = (char**)malloc(sizeof(char*) * SIZE_BEGIN);
}

/* ---------------------------------------------------------*/

void add_graph_node_m (graph_matrix *matrix, char *str) {

    if(matrix -> elm < SIZE_BEGIN) {
        // allocate memory for string
        char *payload_str = malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(payload_str,str);

        matrix -> nodes[matrix -> elm] = payload_str;
        for(int i = (matrix -> elm) * 5; i < (matrix -> elm) * 5 + 5; i++) {
            matrix -> edges[i] = false;
        }

        (matrix -> elm)++;
    } else {
        printf("not enough memory!\n");
        printf("maybe reallocate!\n");
    }
}

/* ---------------------------------------------------------*/

void print_graph_nodes_m (graph_matrix matrix) {
    for(int i = 0; i < matrix.elm; i++) {
        printf("%s\t\t", matrix.nodes[i]);
        int range_begin = i * matrix.elm;
        int range_end = (i * matrix.elm) + matrix.elm;
        for(int j = range_begin; j < range_end; j++) {
            printf("%d ", matrix.edges[j]);
        }
        printf("\n");
    }
}

/* ---------------------------------------------------------*/

int get_node_index (graph_matrix matrix, char *str) {
    int i = 0;
    while(i < matrix.elm) {
        if(strcmp(matrix.nodes[i], str) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

/* ---------------------------------------------------------*/

void add_edge_m (graph_matrix matrix, char  *origin_str, char  *target_str) {
    int index_origin = get_node_index(matrix,origin_str);
    int index_target = get_node_index(matrix,target_str);
    if(index_origin == -1 || index_target == -1) {
        printf("origin or target node does not exist");
        return;
    }
    matrix.edges[matrix.elm * index_origin + index_target] = true;
}

/* ---------------------------------------------------------*/

void remove_all_edges_of_m (graph_matrix matrix, char *str) {
    int index_origin = get_node_index(matrix,str);
    int range_begin = index_origin * matrix.elm;
    int range_end = (index_origin * matrix.elm) + matrix.elm;
    for(int i = range_begin; i < range_end; i++) {
        matrix.edges[i] = false;
    }
}

/* ---------------------------------------------------------*/

void remove_edge_m (graph_matrix  matrix,char *origin_str, char *target_str) {
    int index_origin = get_node_index(matrix,origin_str);
    int index_target = get_node_index(matrix,target_str);
    if(index_origin == -1 || index_target == -1) {
        printf("origin or target node does not exist");
        return;
    }
    matrix.edges[matrix.elm * index_origin + index_target] = false;
}

/* ---------------------------------------------------------*/

void remove_node_m (graph_matrix *matrix, char *str) {
    int index = get_node_index(*matrix,str);

    // remove all edges to given node
    for(int i = 0; i < matrix -> elm; i++) {
        matrix -> edges[(i * matrix -> elm) +index] = false;
    }

    // remove own edges
    remove_all_edges_of_m(*matrix, str);

    // shift bool values to correct position
    for(int i = 0; i < matrix -> elm; i++) {

    }
    // reallocate matrix
        // with size - 1
        // copy all edges and nodes except with index 1
}

/* ---------------------------------------------------------*/
