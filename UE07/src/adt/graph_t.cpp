//
// Created by Michael Neuhold on 29.11.19.
//

#include "graph_t.h"
#include "vertex_t.h"

graph_t::graph_t(std::string graph_name) {
    // graph name
    this -> graph_name = graph_name;
    // allocate memory
    this -> vertex_list = new vertex_t*[this -> vertex_count];
}

void graph_t::add_vertex(vertex_t *vertex) {
    // increment vertex count
    this -> vertex_count++;
    // create nbew tmp vertex array
    vertex_t **new_vertex_array = new vertex_t*[this -> vertex_count];
    for(int i = 0; i < this -> vertex_count - 1; i++) {
        new_vertex_array[i] = this -> vertex_list[i];
    }
    // free old array
    free(this -> vertex_list);
    // old array = new array
    this -> vertex_list = new_vertex_array;
    // insert new vertex
    this -> vertex_list[this -> vertex_count - 1] = vertex;

    /*------------------------------------------------------*/
    // --> i have to set a initial state (0)
    int *matrix_row_ptr = new int[this -> vertex_count]; // new vertex value
    for(int i = 0; i < this -> vertex_count - 1; i++) {
        for(int j = 0; j < this -> vertex_count - 1; j++) {
            matrix_row_ptr[j] = 0;//this -> matrix[i][j];
        }
        matrix_row_ptr[this -> vertex_count - 1] = 0;
       // delete [] this -> matrix;
        this -> matrix[i] = matrix_row_ptr;
    }

    int **matrix_ptr = new int*[this -> vertex_count];
    for(int i = 0; i < this -> vertex_count - 1; i++) {
        matrix_ptr[i] = this->matrix[i];
    }
    matrix_ptr[this -> vertex_count - 1] = new int[this -> vertex_count];
    for(int i = 0; i < this -> vertex_count; i++) {
        matrix_ptr[this -> vertex_count - 1][i] = 0;
    }

    delete [] this -> matrix;
    this -> matrix = matrix_ptr;

    // matrix um einen x-value (origin) erweitern

    // matrix alle y-werte (targets um einen wert erweitern)

}

void graph_t::print() {
    for(int i = 0; i < this -> vertex_count;i++){
        std::cout << this -> vertex_list[i]->get_payload() << std::endl;
    }
}

int graph_t::get_vertex_index(vertex_t *v1) {
    for(int i = 0; i < this -> vertex_count; i++){
        if( this -> vertex_list[i] == v1){
            return i;
        }
    }
    return -1;
}

void graph_t::add_edge(vertex_t *v1, vertex_t *v2, int weight) {
    int origin_index = this -> get_vertex_index(v1);
    int target_index = this -> get_vertex_index(v2);
    if(origin_index == -1 || target_index == -1){
        std::cout << "ERROR - origin or target is no memeber of graph!\n";
        return;
    }
    this -> matrix[origin_index][target_index] = weight;
}

void graph_t::print_matrix() {
    for(int i = 0; i < this -> vertex_count; i++) {
        for(int j = 0; j < this -> vertex_count; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}