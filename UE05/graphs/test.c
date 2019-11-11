#include <stdio.h>
#include <stdlib.h>

#include "./test.h"
#include "./io_lib.h"

// What do you want to test?
#define DELETE_EDGE
#define DELETE_NODE
//#define TOPSORT

int main () {

    graph g1;
    graph g2;
    graph g3;

    // init graph
    graph_init(&g1);
    graph_init(&g2);
    graph_init(&g3);

    // add some nodes
    graph_add_node(&g1, "Node 1");
    graph_add_node(&g1, "Node 2");
    graph_add_node(&g1, "Node 3");
    graph_add_node(&g1, "Node 4");
    graph_add_node(&g1, "Node 5");
    graph_add_node(&g1, "Node 6");

    /*
    print_line();
    printf("graph g1: \n");
    graph_print(g1);
    */
    /*
    graph_add_node(&g2, "Unterhose");
    graph_add_node(&g2, "Pullover");
    graph_add_node(&g2, "Mantel");
    graph_add_node(&g2, "Hose");
    graph_add_node(&g2, "Schuhe");
    graph_add_node(&g2, "Socken");
    graph_add_node(&g2, "Unterhemd");

    */
    // add some edges
    graph_add_edge(g1, "Node 1", "Node 2");
    graph_add_edge(g1, "Node 1", "Node 3");
    graph_add_edge(g1, "Node 1", "Node 4");
    graph_add_edge(g1, "Node 4", "Node 1");
    graph_add_edge(g1, "Node 2", "Node 1");
    graph_add_edge(g1, "Node 3", "Node 4");
    /*
    graph_add_edge(g2, "Unterhose", "Hose");
    graph_add_edge(g2, "Pullover", "Mantel");
    graph_add_edge(g2, "Hose", "Mantel");
    graph_add_edge(g2, "Hose", "Schuhe");
    graph_add_edge(g2, "Socken", "Schuhe");
    graph_add_edge(g2, "Unterhemd", "Pullover");
    */
    /* ---------------------------------------------------------*/

    print_line();
    printf("graph g1: \n");
    graph_print(g1);
/*
    print_line();
    printf("graph g2: \n");
    graph_print(g2);
    */
    /* ---------------------------------------------------------*/

    #ifdef DELETE_EDGE
    print_line();
    printf("delete edge (Node 1 -> Node 3) from g1\n");
    graph_remove_edge(g1,"Node 1", "Node 3");

    /*
    printf("delete edge (Hose -> Mantel) from g2\n");
    graph_remove_edge(g2,"Hose", "Mantel");
    */
    print_line();
    printf("graph g1: \n");
    graph_print(g1);

    print_line();
    printf("graph g2: \n");
    graph_print(g2);
    #endif

    /* ---------------------------------------------------------*/

    #ifdef DELETE_NODE
    print_line();
    printf("delete node (Node 1) from g1\n");
    graph_remove_node(&g1, "Node 1");
/*
    printf("delete node (Schuhe) from g2\n");
    graph_remove_node(&g2, "Schuhe");
*/
    print_line();
    printf("graph g1: \n");
    graph_print(g1);


    /*
    print_line();
    printf("graph g2: \n");
    graph_print(g2);
    */
    #endif

    /* ---------------------------------------------------------*/

    #ifdef TOPSORT
    print_line();
    printf("graph g1 top-sorted: \n");
    graph_topological_sort(g1);

    print_line();
    printf("graph g2 top-sorted: \n");
    graph_topological_sort(g2);

    #endif
    /* ---------------------------------------------------------*/

    return EXIT_SUCCESS;
}
