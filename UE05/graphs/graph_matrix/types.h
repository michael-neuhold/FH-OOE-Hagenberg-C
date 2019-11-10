//
// Created by Michael Neuhold on 09.11.19.
//

#ifndef GRAPHS_TYPES_H
#define GRAPHS_TYPES_H

/* ---------------------------------------------------------*/

#include <stdbool.h>

typedef struct matrix {
    char **nodes;
    bool *edges;
    int elm;
} matrix;

typedef matrix graph_matrix;

/* ---------------------------------------------------------*/

#endif //GRAPHS_TYPES_H
