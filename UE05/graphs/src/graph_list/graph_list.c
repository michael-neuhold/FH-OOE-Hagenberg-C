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

#include <stdio.h>

/* -------------------------------------------------*/

// Init
void PREFIX_LIST (init_graph_list) () {
  graph_list *graph;
  graph = NULL;
  return;
}

/* -------------------------------------------------*/

void PREFIX_LIST (connect_graph_nodes) (graph_list * graph, graph_node *target) {

}

/* -------------------------------------------------*/
/* returns graph node ptr (new node) with payload */
graph_node_ptr PREFIX_LIST (new_graph_node) (char *payload) {
  char *pl = (char*)malloc(sizeof(char) * strlen(payload) + 1);
  strcpy(*pl,payload);
  graph_node_ptr n = (graph_node_ptr)malloc(sizeof(graph_node));
  n -> payload = pl;
  n -> edges_list = NULL;
  n -> next = NULL;
  return n;
}

/* -------------------------------------------------*/
/* returns graph edge node ptr (new node) with target */
graph_edge_node_ptr PREFIX_LIST (new_edge_node) (graph_node *target) {
  graph_edge_node_ptr n = (graph_edge_node_ptr)malloc(sizeof(graph_edge_node));
  n -> target = target;
  n -> next = NULL;
  return n;
}

/* -------------------------------------------------*/
/* prepends new node to graph list */
void PREFIX_LIST (prepend_graph_node) (graph_node_ptr *list, graph_node_ptr n) {
  n = *list;
  *list = n;
  return;
}

/* -------------------------------------------------*/

void PREFIX_LIST (prepend_edge_node) (graph_edge_node_ptr *list, graph_edge_node_ptr n) {
  n = *list;
  *list = n;
  return;
}

/* -------------------------------------------------*/

void PREFIX_LIST (delete_graph_node) (graph_list **graph, char *payload) {

}

/* -------------------------------------------------*/

void PREFIX_LIST (delete_edge_node) (graph_list **graph, char *payload) {
  
  //
  char *pl = (char*)malloc(sizeof(char) * strlen(payload) + 1);
  strcpy(*pl,payload);

  while(((*graph) -> next == NULL) && strcmp((*graph) -> payload,*pl) == 0) {
    *graph = (*graph) -> next;
  }

}

/* -------------------------------------------------*/

void PREFIX_LIST (dispose_list) (graph_list **list) {

}

/* -------------------------------------------------*/
// returns address or 0 
void PREFIX_LIST (dispose_list) (graph_list **list) {

}