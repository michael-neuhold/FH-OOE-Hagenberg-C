//       $Id: graph_list.h 2319 2019-11-03 09:32:33Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Aufgaben/WS16/VZ/src/graphs/src/graph_list/graph_list.h $
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

#if !defined GRAPH_LIST_H
#define      GRAPH_LIST_H

#include "../graph_selector.h"

/* typedef struct graph_list {
  
} graph_list; */

typedef struct graph_node graph_list;

typedef struct graph_node {
  char *payload;
  struct graph_edge_node *edges_list;
  struct graph_node *next;
} graph_node;

typedef struct graph_node *graph_node_ptr;

typedef struct graph_edge_node {
  graph_node *target;
  struct graph_edge_node *next;
} graph_edge_node;

typedef struct graph_edge_node *graph_edge_node_ptr;

graph_list PREFIX_LIST (init_graph_list) ();
void PREFIX_LIST (connect_graph_nodes) (graph_list * graph, graph_node *target);
graph_node_ptr PREFIX_LIST (new_graph_node) (char *payload);
graph_edge_node_ptr PREFIX_LIST (new_edge_node) (graph_node *target);
void PREFIX_LIST (append_node) (graph_list **graph, char *payload);
void PREFIX_LIST (delete_node) (graph_list **graph, char *payload);

#endif   // GRAPH_LIST_H
