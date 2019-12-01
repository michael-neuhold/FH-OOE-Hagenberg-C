//
// Created by Michael Neuhold on 29.11.19.
//

#include <cstring>
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

handle_t graph_t::add_vertex(vertex_t &vertex) {

    // check if vertex exists already
    if(this -> vertex_exists(vertex)) {
        std::cout << vertex.get_payload() <<" Vertex is alredy memeber of thius graph!!\n";
        handle_t invalid(-1);
        return invalid;
    }

    this -> vertex_count++;

    if(this -> vertex_count - 1 == 0) {
        this -> vertex_list = new vertex_t*[1];
        this -> vertex_list[this -> vertex_count - 1] = &vertex;

        this -> matrix = new int*[1];
        this -> matrix[0] = new int[1];
        this -> matrix[0][0] = 0;
    } else {
        this -> vertex_list = (vertex_t**)realloc(this -> vertex_list, sizeof(vertex_t*) * this -> vertex_count);
        this -> vertex_list[this -> vertex_count - 1] = &vertex;

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

void graph_t::print() {
    for(int i = 0; i < this -> vertex_count;i++){
        std::cout << this -> vertex_list[i]->get_payload() << std::endl;
    }
}

/*---------------------------------------------------------------------------------*/

int graph_t::get_vertex_index(vertex_t *v1) {
    for(int i = 0; i < this -> vertex_count; i++){
        if( this -> vertex_list[i] == v1){
            return i;
        }
    }
    return -1;
}

/*---------------------------------------------------------------------------------*/

void graph_t::add_edge(handle_t const from, handle_t const to, int const weight) {
    this -> matrix[from.getIdentifier()][to.getIdentifier()] = weight;
}

/*---------------------------------------------------------------------------------*/

void graph_t::print_matrix() {
    std::cout << " ";
    for(int i = 0; i < this -> vertex_count; i++){
        std::cout << " " << this -> vertex_list[i] -> get_payload();
    }
    std::cout << std::endl;
    for(int i = 0; i < this -> vertex_count; i++) {
        std::cout << this -> vertex_list[i] -> get_payload() << " ";
        for(int j = 0; j < this -> vertex_count; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

/*---------------------------------------------------------------------------------*/

bool graph_t::vertex_exists(vertex_t &vertex) {
    int i = 0;
    while(i < this -> vertex_count) {
        if(vertex_list[i] -> get_payload() == vertex.get_payload()){
            return true;
        }
        i++;
    }
    return false;
}

/*---------------------------------------------------------------------------------*/

int graph_t::shortest_path (handle_t const from, handle_t const to) const {
    std::cout << "shortest path\n";
    return 1;
}