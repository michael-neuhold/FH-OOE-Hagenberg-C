//       $Id: graph_includer.h 2319 2019-11-03 09:32:33Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Aufgaben/WS16/VZ/src/graphs/src/graph_includer.h $
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

#if !defined GRAPH_INCLUDER_H
#define      GRAPH_INCLUDER_H

/* basic standard includes */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "./graph_selector.h"

#if defined TEST_GRAPH_LIST
   #include "./graph_list/graph_list.h"

   typedef graph_list graph_t;

#elif defined TEST_GRAPH_MATRIX
   #include "./graph_matrix/graph_matrix.h"

   typedef graph_matrix graph_t;
#endif

#endif   // GRAPH_INCLUDER_H
