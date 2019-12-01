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
    vertex_t v3("C");
    vertex_t v4("D");
    vertex_t v5("E");

    // add vertex to graph
    handle_t h1 = g1.add_vertex(v1);
    handle_t h2 = g1.add_vertex(v2);
    handle_t h3 = g1.add_vertex(v3);
    handle_t h4 = g1.add_vertex(v4);
    handle_t h5 = g1.add_vertex(v5);
    handle_t h6 = g1.add_vertex(v5);

    // print matrix
    g1.print_matrix();
    Separator();

    // add edges to graph
    g1.add_edge(h1,h2,6);
    g1.add_edge(h1,h4,1);
    g1.add_edge(h4,h2,2);
    g1.add_edge(h4,h5,1);
    g1.add_edge(h5,h3,5);
    g1.add_edge(h2,h3,5);
    g1.add_edge(h2,h5,4);

    // print matrix
    g1.print_matrix();
    Separator();

    return 0;
}