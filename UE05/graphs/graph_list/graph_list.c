//       $Id: graph_list.c 2319 2019-11-03 09:32:33Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Aufgaben/WS16/VZ/src/graphs/src/graph_list/graph_list.c $
// $Revision: 2319 $
//     $Date: 2019-11-03 10:32:33 +0100 (So., 03 Nov 2019) $
//   $Author: p20068 $
//   Creator: Peter Kulczycki (peter.kulczycki<AT>fh-hagenberg.at)
//  Creation: November, 2019
// Copyright: (c) 2019 Peter Kulczycki
//   License: This document contains proprietary information belonging to
//            University of Applied Sciences Upper Austria, Campus Hagenberg.
//            It is distributed under the Boost Software License, Version 1.0
//            (see http://www.boost.org/LICENSE_1_0.txt).

#include "./graph_list.h"
#include "./edge_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* ---------------------------------------------------------*/

graph_node_ptr new_node (char *str) {
    char *payload = malloc(sizeof(char) * strlen(str) + 1);
    strcpy(payload,str);
    graph_node_ptr n = malloc(sizeof(graph_list_node));
    n -> payload = payload;
    n -> edges = NULL;
    n -> next = NULL;
    return n;
}

bool node_exists(graph_list list, char *str) {
    graph_list l = list;
    while(l != NULL && strcmp(l -> payload,str) != 0) {
        l = l -> next;
    }
    return (l != NULL) ? true : false;
}

/* ---------------------------------------------------------*/

void PREFIX_LIST (prepend) (graph_list *list, graph_node_ptr node) {
    node -> next = *list;
    *list = node;
}

/* ---------------------------------------------------------*/

void PREFIX_LIST (init_graph_list) (graph_list *list) {
    *list = NULL;
}

/* ---------------------------------------------------------*/

void PREFIX_LIST (add_graph_node) (graph_list *list, char *str) {
    // check if node already exists
    if(node_exists(*list,str)) {
        printf("node exists already: %s\n", str);
        return;
    }
    // prepend node:
    prepend(list, new_node(str));
}

/* ---------------------------------------------------------*/

void PREFIX_LIST (print_graph_nodes) (graph_node_ptr list) {
    graph_node_ptr l = list;
    printf("\n---------------------\n");
    while(l != NULL) {
        printf("%s", l -> payload);
        printf(" | --> ");
        print_edge_list(l -> edges);
        l = l -> next;
        printf("\n---------------------\n");
    }
    printf("\n\nEND\n\n");
}

/* ---------------------------------------------------------*/

void PREFIX_LIST (remove_graph_node) (graph_node_ptr *list, char *str) {
    graph_node_ptr prev = NULL;
    graph_node_ptr l = *list;
    graph_node_ptr n = NULL;
    while(l != NULL && strcmp(l -> payload,str) != 0) {
        prev = l;
        l = l -> next;
    }
    if(l != NULL && prev != NULL) {
        remove_edge_list(&(l -> edges));    // remove edge list
        prev -> next = l -> next;
        l -> next = NULL;
        free(n);
    } else if(l != NULL) {
        remove_edge_list(&(l -> edges));    // remove edge list
        *list = (*list) -> next;
        free(l);
    }
}

/* ---------------------------------------------------------*/

graph_node_ptr getNode(graph_list list, char *str) {
    graph_list l = list;
    while(l != NULL && strcmp(l -> payload,str) != 0) {
        l = l -> next;
    }
    return (l != NULL) ? l : NULL;
}

/* ---------------------------------------------------------*/

bool edge_exists(graph_node_ptr origin, graph_node_ptr target) {
    edge_node_ptr enp = origin -> edges;
    graph_node_ptr n;
    while(enp != NULL) {
        n = enp -> target;
        printf("target: %s || edge list: %s\n", target -> payload, n -> payload);
        if(strcmp(target -> payload, n -> payload) == 0) {
            printf("edge already exists!\n");
            return true;
        }
        enp = enp -> next;
    }
    return false;
}

/* ---------------------------------------------------------*/

void PREFIX_LIST (add_edge) (graph_list list, char  *origin_str, char  *target_str) {
    graph_node_ptr origin = getNode(list, origin_str);
    graph_node_ptr target = getNode(list, target_str);

    if( origin == NULL || target == NULL) {
        printf("origin or target node does not exist!");
        return;
    }

    // to prevent edge duplication
    if(!edge_exists(origin,target)){
        prepend_edge_node(&(origin -> edges), new_edge_node(target));
    }
}

/* ---------------------------------------------------------*/

void PREFIX_LIST (remove_all_edges_of) (graph_list list, char *str) {
    graph_node_ptr node = getNode(list,str);
    if(node == NULL) {
        printf("node does not exist!\n");
        return;
    }
    remove_edge_list(&(node -> edges));
}

/* ---------------------------------------------------------*/

void PREFIX_LIST (remove_edge) (graph_list  list, char *origin_str, char *target_str) {
    graph_node_ptr origin = getNode(list, origin_str);
    graph_node_ptr target = getNode(list, target_str);

    if(origin == NULL || target == NULL) {
        printf("origin or target node not exist");
        return;
    }

    edge_node_ptr el = origin -> edges; // el = edge list of origin node
    edge_node_ptr prev = NULL; // prev pointer - necessary to delete edge
    while(el != NULL && el -> target != target) {
        prev = el;
        el = el -> next;
    }

    if(el != NULL && prev != NULL) {
        prev -> next = el -> next;
        el -> next = NULL;
        free(el);
    } else if(el != NULL) {
        origin -> edges = origin -> edges -> next;
    } else {
        printf("entered edge does not exist!\n");
    }
}

/* ---------------------------------------------------------*/
