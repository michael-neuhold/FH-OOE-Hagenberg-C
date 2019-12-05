//
// Created by Michael Neuhold on 29.11.19.
//

#include "graph_t.h"
#include "vertex_t.h"
#include "handle_t.h"

/*---------------------------------------------------------------------------------*/

graph_t::graph_t(std::string graph_name) {
    // graph name
    this -> graph_name = graph_name;
    // allocate memory
    this -> vertex_list = new vertex_t*[this -> vertex_count];
}

/*---------------------------------------------------------------------------------*/

handle_t graph_t::add_vertex(vertex_t vertex) {
    vertex_t *v = new vertex_t {vertex.get_payload()};

    this -> vertex_count++;
    if(this -> vertex_count - 1 == 0) {
        this -> vertex_list = new vertex_t*[1];
        this -> vertex_list[this -> vertex_count - 1] = v;

        this -> matrix = new int*[1];
        this -> matrix[0] = new int[1];
        this -> matrix[0][0] = 0;
    } else {
        this -> vertex_list = (vertex_t**)realloc(this -> vertex_list, sizeof(vertex_t*) * this -> vertex_count);
        this -> vertex_list[this -> vertex_count - 1] = v;

        this -> matrix = (int**)realloc(this -> matrix, sizeof(int*) * this -> vertex_count);
        for(int i = 0; i < this -> vertex_count - 1; i++) {
            this -> matrix[i] = (int*)realloc(this -> matrix[i], sizeof(int) * this -> vertex_count);
            this -> matrix[i][vertex_count - 1] = 0;
        }
        this -> matrix[vertex_count - 1] = new int[vertex_count];
        for(int i = 0; i < vertex_count; i++) {
            this -> matrix[vertex_count - 1][i] = 0;
        }
    }

    handle_t handler(vertex_count - 1);
    return handler;
}

/*---------------------------------------------------------------------------------*/

std::ostream & graph_t::print (std::ostream & out) const {
    out << this -> graph_name << "\n";
    out << " ";
    for(int i = 0; i < this -> vertex_count; i++){
        out << " " << this -> vertex_list[i] -> get_payload();
    }
    out << std::endl;
    for(int i = 0; i < this -> vertex_count; i++) {
        out << this -> vertex_list[i] -> get_payload() << " ";
        for(int j = 0; j < this -> vertex_count; j++) {
            out << matrix[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

/*---------------------------------------------------------------------------------*/

void graph_t::add_edge(handle_t const from, handle_t const to, int const weight) {
    this -> matrix[from.getIdentifier()][to.getIdentifier()] = weight;
}

/*---------------------------------------------------------------------------------*/
// shortest path algorithm

static bool in_visited(int i, int* vertex_visited, int n) {
    int j = 0;
    while(j < n) {
        if(i == vertex_visited[j]) {
            return true;
        }
        j++;
    }
    return false;
}

void graph_t::dijkstra(int from, int *vertex_visited, int *shortest_path, int not_visited_count, int current_path) const {
    if(not_visited_count == 0) {
        return;
    }
    int current_shortest_path = INT_MAX;
    int current_shortest_index = INT_MAX;
    for(int i = 0; i < this -> vertex_count; i++) {
        if(this -> matrix[from][i]) {
            if(shortest_path[i] > current_path + this -> matrix[from][i]) {
                shortest_path[i] = current_path + this -> matrix[from][i];
            }
            if(current_shortest_path > this -> matrix[from][i] && !in_visited(i, vertex_visited, this -> vertex_count - not_visited_count)) {
                current_shortest_path = this -> matrix[from][i];
                current_shortest_index = i;
            }
        }
    }
    if(current_shortest_index != INT_MAX) {
        vertex_visited[this -> vertex_count - not_visited_count] = current_shortest_index;
        dijkstra(current_shortest_index, vertex_visited, shortest_path, not_visited_count - 1, current_path + current_shortest_path);
    } else {
        return;
    }
}

int graph_t::shortest_path (handle_t const from, handle_t const to) const {
    int *vertex_vistited = new int[this -> vertex_count];
    int *shortest_path = new int[this -> vertex_count];
    for(int i = 0; i < this -> vertex_count;i++) {
        shortest_path[i] = INT_MAX;
    }
    shortest_path[from.getIdentifier()] = 0;
    int current_path{0};
    dijkstra(from.getIdentifier(),vertex_vistited,shortest_path, this -> vertex_count, current_path);

    // return to-entry from shortest path "table"
    return shortest_path[to.getIdentifier()];
}

/*---------------------------------------------------------------------------------*/

graph_t::~graph_t() {
    // free allocated memory
    for(int i = 0; i < this -> vertex_count; i++) {
        delete [] this -> matrix[i];
    }
    delete [] this -> matrix;
    delete [] this -> vertex_list;
}

/*---------------------------------------------------------------------------------*/
