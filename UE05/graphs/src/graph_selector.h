//       $Id: graph_selector.h 2319 2019-11-03 09:32:33Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Aufgaben/WS16/VZ/src/graphs/src/graph_selector.h $
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

#if !defined GRAPH_SELECTOR_H
#define      GRAPH_SELECTOR_H

// -----------------------------------------------------------------------------

// #define TEST_GRAPH_LIST     // Either define TEST_GRAPH_LIST or TEST_GRAPH_MATRIX
   #define TEST_GRAPH_MATRIX   // here in source or via the compiler option -D.

// -----------------------------------------------------------------------------

#if defined TEST_GRAPH_LIST
   #define PREFIX_LIST(name)         name
   #define PREFIX_MATRIX(name) xxx_##name

#elif defined TEST_GRAPH_MATRIX
   #define PREFIX_LIST(name)   xxx_##name
   #define PREFIX_MATRIX(name)       name

#else
   #error "Define (just) one of 'TEST_GRAPH_LIST' or 'TEST_GRAPH_MATRIX'."
#endif

#endif   // GRAPH_SELECTOR_H
