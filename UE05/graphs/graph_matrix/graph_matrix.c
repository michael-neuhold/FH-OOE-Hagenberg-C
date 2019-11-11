//
// Created by Michael Neuhold on 09.11.19.
//

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./graph_matrix.h"

/* ---------------------------------------------------------*/

void init_graph_m (graph_matrix *matrix) {
    matrix -> elm = 0;
    matrix -> nodes = NULL;
    matrix -> edges = NULL;
}

/* ---------------------------------------------------------*/

void add_graph_node_m (graph_matrix *matrix, char *str) {

    // allocate payload
    char *payload = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(payload,str);

    if(matrix -> elm == 0) {
        // allocate first element
        matrix -> nodes = (char**)malloc(sizeof(char*));
        matrix -> nodes[0] = payload;

        matrix -> edges = (bool**)malloc(sizeof(bool*));
        matrix -> edges[0] = (bool*)malloc(sizeof(bool));
        matrix -> edges[0][0] = false;

    } else {
        // allocate n element
        matrix -> nodes = (char**)realloc(matrix -> nodes, sizeof(char*) * (matrix -> elm + 1));
        matrix -> nodes[matrix -> elm] = payload;

        matrix -> edges = (bool**)realloc(matrix -> edges, sizeof(bool*) * (matrix -> elm + 1));
        for(int i = 0; i < matrix -> elm; i++) {
            matrix -> edges[i] = (bool*)realloc(matrix -> edges[i], sizeof(bool) * (matrix -> elm + 1));
            matrix -> edges[i][matrix -> elm] = false;
        }
        matrix -> edges[matrix -> elm] = (bool*)malloc(sizeof(bool) * (matrix -> elm + 1));
        for(int i = 0; i <= matrix -> elm; i++) {
            matrix -> edges[matrix -> elm][i] = false;
        }
    }
    matrix -> elm++;
}

/* ---------------------------------------------------------*/

void print_graph_nodes_m (graph_matrix matrix) {
    printf("---> print\n");
    printf("\t\t");
    for(int i = 0; i < matrix.elm; i++) { printf("%s\t", matrix.nodes[i]); }
    printf("\n");
    for(int i = 0; i < matrix.elm; i++) {
        printf("%s\t", matrix.nodes[i]);
        for(int j = 0; j < matrix.elm; j++) {
            printf("%d\t\t", (matrix.edges[i])[j]);
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
    int origin_index = get_node_index(matrix, origin_str);
    int target_index = get_node_index(matrix, target_str);

    printf("found indexes\n");

    if(target_index == -1 || origin_index == -1) {
        printf("origin or target node does not exist!\n");
        return;
    }

    (matrix.edges[origin_index])[target_index] = true;
}

/* ---------------------------------------------------------*/

void remove_edge_m (graph_matrix  matrix,char *origin_str, char *target_str) {
    int origin_index = get_node_index(matrix, origin_str);
    int target_index = get_node_index(matrix, target_str);

    printf("found indexes\n");

    if(target_index == -1 || origin_index == -1) {
        printf("origin or target node does not exist!\n");
        return;
    }

    (matrix.edges[origin_index])[target_index] = false;
}

/* ---------------------------------------------------------*/

void remove_node_m (graph_matrix *matrix, char *str) {
    int index = get_node_index(*matrix, str);

    free((matrix -> edges)[index]);
    (matrix -> edges)[index] = NULL;

    free((matrix -> nodes)[index]);
    (matrix -> edges)[index] = NULL;

    if(matrix -> elm == 1) {
        matrix -> edges = NULL;
        matrix -> nodes = NULL;
    } else {
        for(int i = index + 1; i < matrix -> elm; i++) {
            (matrix -> edges)[i-1] = (matrix -> edges)[i];
            (matrix -> nodes)[i-1] = (matrix -> nodes)[i];
        }
        matrix -> edges = (bool**)realloc(matrix -> edges, sizeof(bool*) * (matrix -> elm-1));
        matrix -> nodes = (char**)realloc(matrix -> nodes, sizeof(char*) * (matrix -> elm-1));

        for(int i = 0; i < matrix -> elm-1; i++) {
            for(int j = index + 1; j < matrix -> elm; j++) {
                (matrix -> edges[i])[j-1] = (matrix -> edges[i])[j];
            }
            (matrix -> edges)[i] = (bool*)realloc((matrix -> edges)[i], sizeof(bool) * matrix -> elm-1);
        }
    }

    matrix -> elm--;
    printf("end--\n");
}

/* ---------------------------------------------------------*/