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
    graph_t g2("Graph 2");

    // create new vertex
    vertex_t v1("A");
    vertex_t v2("B");
    vertex_t v3("C");
    vertex_t v4("D");
    vertex_t v5("E");

    vertex_t v6("X");
    vertex_t v7("Y");
    vertex_t v8("Z");

    // add vertex to graph
    handle_t A = g1.add_vertex(v1);
    handle_t B = g1.add_vertex(v2);
    handle_t C = g1.add_vertex(v3);
    handle_t D = g1.add_vertex(v4);
    handle_t E = g1.add_vertex(v5);

    handle_t X = g2.add_vertex(v6);
    handle_t Y = g2.add_vertex(v7);
    handle_t Z = g2.add_vertex(v8);

    // print graph
    g1.print(std::cout);
    Separator();
    g2.print(std::cout);
    Separator();

    // add edges to graph
    g1.add_edge(A,B,6); // A -> B
    g1.add_edge(A,D,1); // A -> D
    g1.add_edge(D,B,2); // D -> B
    g1.add_edge(D,E,1); // D -> E
    g1.add_edge(E,C,5); // E -> C
    g1.add_edge(E,B,2); // B -> C
    g1.add_edge(B,C,5); // E -> B

    g2.add_edge(X,Y,4);
    g2.add_edge(Y,Z,3);

    // print graph
    g1.print(std::cout);
    Separator();
    g2.print(std::cout);
    Separator();

    // shortest path
    cout << "g1 shortest path from A to C: " << g1.shortest_path(A,C) << endl;
    cout << "g1 shortest path from A to B: " << g1.shortest_path(A,B) << endl;

    Separator();

}