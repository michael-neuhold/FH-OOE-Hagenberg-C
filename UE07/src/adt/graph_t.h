//
// Created by Michael Neuhold on 29.11.19.
//

#ifndef ADT_GRAPH_T_H
#define ADT_GRAPH_T_H

#include "./vertex_t.h"

class graph_t {
public:
    graph_t(std::string graph_name);
    void print();
    void print_matrix();
    // add vertex
    void add_vertex(vertex_t *vertex);
    // add edge
    void add_edge(vertex_t *v1, vertex_t *v2, int weight);
private:
    std::string graph_name{"test1"};
    int vertex_count{0};

    // graph node dyn. array
    vertex_t **vertex_list;
    // graph edges adj. matrix 2-dimensional
    int **matrix;

    // get index of vertex
    int get_vertex_index(vertex_t *v1);
};

#endif //ADT_GRAPH_T_H
