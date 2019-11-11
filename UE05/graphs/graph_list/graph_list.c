//
// Created by Michael Neuhold on 09.11.19.
//


#include "./graph_list.h"
#include "./edge_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

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

void init_graph_l (graph_list *list) {
    *list = NULL;
}

/* ---------------------------------------------------------*/

void prepend (graph_list *list, graph_node_ptr node) {
    node -> next = *list;
    *list = node;
}

/* ---------------------------------------------------------*/

void add_graph_node_l (graph_list *list, char *str) {
    // check if node already exists
    if(node_exists(*list,str)) {
        printf("node exists already: %s\n", str);
        return;
    }
    // prepend node:
    prepend(list, new_node(str));
}

/* ---------------------------------------------------------*/

void print_graph_nodes_l (graph_node_ptr list) {
    graph_node_ptr l = list;
    printf("\n---------------------\n");
    while(l != NULL) {
        printf("%s", l -> payload);
        printf(" | --> ");
        print_edge_list(l -> edges);
        l = l -> next;
        printf("\n---------------------\n");
    }
}

/* ---------------------------------------------------------*/

void remove_edges_to_node(graph_node_ptr list, graph_node_ptr node) {
    edge_node_ptr edges_list;
    graph_node_ptr l = list;
    while(l != NULL) {
        edges_list = l -> edges;
        while(edges_list != NULL) {
            //printf("checking node: %s\n", edges_list -> target -> payload);
            if(edges_list -> target == node) {
                //printf("delete\n");
                //printf("origin: %s, target: %s\n", l -> payload ,edges_list -> target -> payload);
                remove_edge_l(list,l -> payload, edges_list -> target -> payload);
            }
            edges_list = edges_list -> next;
        }
        l = l -> next;
    }
}

void remove_node_l (graph_node_ptr *list, char *str) {
    graph_node_ptr prev = NULL;
    graph_node_ptr l = *list;
    graph_node_ptr n = NULL;
    while(l != NULL && strcmp(l -> payload,str) != 0) {
        prev = l;
        l = l -> next;
    }
    if(l != NULL && prev != NULL) {
        remove_edges_to_node(*list, l);     // remove all edges on this node
        remove_edge_list(&(l -> edges));    // remove edge list
        prev -> next = l -> next;
        l -> next = NULL;
        free(n);
    } else if(l != NULL) {
        // remove all edges on this node
        remove_edges_to_node(*list, l);

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
        //printf("target: %s || edge list: %s\n", target -> payload, n -> payload);
        if(strcmp(target -> payload, n -> payload) == 0) {
            printf("edge already exists!\n");
            return true;
        }
        enp = enp -> next;
    }
    return false;
}

/* ---------------------------------------------------------*/

void add_edge_l (graph_list list, char  *origin_str, char  *target_str) {
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

void remove_all_edges_of_l (graph_list list, char *str) {
    graph_node_ptr node = getNode(list,str);
    if(node == NULL) {
        printf("node does not exist!\n");
        return;
    }
    remove_edge_list(&(node -> edges));
}

/* ---------------------------------------------------------*/

void remove_edge_l (graph_list  list, char *origin_str, char *target_str) {
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
// TODO: free list

/* ---------------------------------------------------------*/

// top sort

int get_as_target_count(graph_list list, char *str) {
    int count = 0;
    edge_node_ptr edges = NULL;
    while(list != NULL) {
        edges = list -> edges;
        while(edges != NULL) {
            if(strcmp(edges -> target -> payload,str) == 0) {
                count++;
            }
            edges = edges -> next;
        }
        list = list -> next;
    }
    return count;
}

bool is_target(graph_list list, graph_node_ptr node) {
    while(list != NULL) {
        if(edge_exists(list, node)) return true;
        list = list -> next;
    }
    return false;
}

void topological_sort_l(graph_list list) {
    graph_list original_list = list;
    graph_node_ptr curr_node = list;
    graph_list sorted_nodes = NULL;

    while(original_list != NULL) {
        int min_cnt = INT_MAX;
        graph_node_ptr min_node = NULL;
        curr_node = original_list;
        while (curr_node != NULL) {
            // get count node as target
            if(get_as_target_count(original_list,curr_node -> payload) < min_cnt) {
                min_cnt = get_as_target_count(original_list,curr_node -> payload);
                min_node = curr_node;
            }
            curr_node = curr_node -> next;
        }
        if(min_node != NULL) {
            printf("| %s | ", min_node->payload);
            // remove min_node
            remove_node_l(&original_list, min_node->payload);
        }
    }
    printf("\n");
}
