//
// Created by Michael Neuhold on 29.11.19.
//

#ifndef ADT_GRAPH_T_H
#define ADT_GRAPH_T_H

#include "./vertex_t.h"
#include "./handle_t.h"

class graph_t {

public:

    graph_t() = delete;
    graph_t(std::string graph_name);
    ~graph_t();
    handle_t add_vertex(vertex_t vertex);
    void add_edge(handle_t const from, handle_t const to, int weight);
    int shortest_path (handle_t const from, handle_t const to) const;
    std::ostream & print (std::ostream & out) const;

private:
    std::string graph_name{"test1"};
    int vertex_count{0};
    vertex_t **vertex_list;
    int **matrix;
    void dijkstra(int from, int *vertex_visited, int *shortest_path, int not_visited_count, int current_path) const;

};

#endif //ADT_GRAPH_T_H
