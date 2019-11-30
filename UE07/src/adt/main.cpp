#include <iostream>
#include "./vertex_t.h"
#include "./graph_t.h"

using namespace std;

void Separator() {
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;
}

void Header(const string &header_text) {
    Separator();
    cout << header_text << endl;
    Separator();

}

int main() {
    Header("graphs");

    // create new graph
    graph_t g1("Graph 1");
    // create new vertex
    vertex_t v1("A");
    vertex_t v2("B");
    vertex_t v3("c");
    vertex_t v4("D");
    vertex_t v5("E");
    vertex_t v6("F");

    // add vertex to graph
    g1.add_vertex(&v1);
    g1.add_vertex(&v2);
    g1.add_vertex(&v3);
    g1.add_vertex(&v4);
    g1.add_vertex(&v5);
    g1.add_vertex(&v6);

    // print matrix
    g1.print_matrix();


    g1.print();
    return 0;
}