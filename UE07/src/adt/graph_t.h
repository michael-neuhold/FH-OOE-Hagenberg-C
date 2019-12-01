//
// Created by Michael Neuhold on 29.11.19.
//

#ifndef ADT_GRAPH_T_H
#define ADT_GRAPH_T_H

#include "./vertex_t.h"
#include "./handle_t.h"

class graph_t {

public:
    graph_t(std::string graph_name);
    void print();
    void print_matrix();
    handle_t add_vertex(vertex_t &vertex);
    void add_edge(handle_t const from, handle_t const to, int weight);
    bool vertex_exists(vertex_t &vertex);
    int shortest_path (handle_t const from, handle_t const to) const;

private:
    std::string graph_name{"test1"};
    int vertex_count{0};
    vertex_t **vertex_list;
    int **matrix;
    int get_vertex_index(vertex_t *v1);

};

#endif //ADT_GRAPH_T_H
