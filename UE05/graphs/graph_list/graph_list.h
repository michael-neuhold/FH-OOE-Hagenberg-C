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

/* ---------------------------------------------------------*/

#include "../graph_selector.h"
#include <stdbool.h>
#include "./types.h"

/* ---------------------------------------------------------*/

void PREFIX_LIST (init_graph_list) (graph_list *list);
void PREFIX_LIST (add_graph_node) (graph_list *list, char *str);
void PREFIX_LIST (print_graph_nodes) (graph_node_ptr list);
void PREFIX_LIST (remove_graph_node) (graph_node_ptr *list, char *str);
void PREFIX_LIST (add_edge) (graph_list list, char  *origin_str, char  *target_str);
void PREFIX_LIST (remove_all_edges_of) (graph_list list, char *str);
void PREFIX_LIST (remove_edge) (graph_list  list,char *origin_str, char *target_str);

/* ---------------------------------------------------------*/

graph_node_ptr new_node(char *str);
void prepend (graph_list *list, graph_node_ptr node);
bool node_exists(graph_list list, char *str);
bool edge_exists(graph_node_ptr origin, graph_node_ptr target);

/* ---------------------------------------------------------*/

#endif   // GRAPH_LIST_H
