//       $Id: test.c 2319 2019-11-03 09:32:33Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Aufgaben/WS16/VZ/src/graphs/src/test.c $
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

#include "./graph_includer.h"

#include <stdlib.h>
#include <stdio.h>
int main () {

    graph_list l1;

    PREFIX_LIST (init_graph_list)(&l1);

    PREFIX_LIST (add_graph_node)(&l1, "test1");
    PREFIX_LIST (add_graph_node)(&l1, "test2");
    PREFIX_LIST (add_graph_node)(&l1, "test3");
    PREFIX_LIST (add_graph_node)(&l1, "test1");
    PREFIX_LIST (add_graph_node)(&l1, "test4");

    PREFIX_LIST (print_graph_nodes)(l1);

    PREFIX_LIST (add_edge)(l1, "test1", "test2");
    PREFIX_LIST (add_edge)(l1, "test1", "test3");
    PREFIX_LIST (add_edge)(l1, "test1", "test4");

    PREFIX_LIST (add_edge)(l1, "test4", "test1");
    PREFIX_LIST (add_edge)(l1, "test4", "test2");

    // test case edge does already exist
    PREFIX_LIST (add_edge)(l1, "test1", "test2");

    // test case target does not exist
    PREFIX_LIST (add_edge)(l1, "test4", "test9");

    PREFIX_LIST (print_graph_nodes)(l1);

    // test to remove a whole edge list
    //PREFIX_LIST (remove_all_edges_of)(l1,"test1");

    // test to remove distinct edge
    PREFIX_LIST (remove_edge) (l1,"test1", "test4");

    PREFIX_LIST (print_graph_nodes)(l1);

    //PREFIX_LIST (remove_graph_node)(&l1, "test4");
    //PREFIX_LIST (print_graph_nodes)(l1);
    return EXIT_SUCCESS;
}
