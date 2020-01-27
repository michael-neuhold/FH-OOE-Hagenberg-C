//       $Id: main.cpp 2382 2020-01-09 09:31:58Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Uebungen/minilib/intro-1/src/main.cpp $
// $Revision: 2382 $
//     $Date: 2020-01-09 10:31:58 +0100 (Do., 09 Jän 2020) $
//   Creator: Peter Kulczycki
//  Creation: January, 2020
//   $Author: p20068 $
// Copyright: (c) 2020 Peter Kulczycki (peter.kulczycki<AT>fh-hagenberg.at)
//   License: This document contains proprietary information belonging to
//            University of Applied Sciences Upper Austria, Campus Hagenberg. It
//            is distributed under the Boost Software License, Version 1.0 (see
//            http://www.boost.org/LICENSE_1_0.txt).

#include <ml5/ml5.h>

int main () {
   std::cout << "detected os:       " << ml5::util::detected_os_as_string () << "\n"
                "detected compiler: " << ml5::util::detected_compiler_as_string () << "\n"
                "MiniLib version:   " << ml5::version << "\n\n";
}
