//       $Id: forwards.h 607 2019-11-02 22:46:30Z p27116 $
//      $URL: https://svn01.fh-hagenberg.at/se/minilib/ml5/trunk/product/ml5/inc/ml5/utility/forwards.h $
// $Revision: 607 $
//     $Date: 2019-11-02 23:46:30 +0100 (Sa., 02 Nov 2019) $
//   Creator: peter.kulczycki<AT>fh-hagenberg.at
//  Creation: June 1, 2018
//   $Author: p27116 $
// Copyright: (c) 2018 Peter Kulczycki (peter.kulczycki<AT>fh-hagenberg.at)
//            (c) 2018 Michael Hava (michael.hava<AT>fh-hagenberg.at)
//   License: This document contains proprietary information belonging to
//            University of Applied Sciences Upper Austria, Campus Hagenberg. It
//            is distributed under the Boost Software License, Version 1.0 (see
//            http://www.boost.org/LICENSE_1_0.txt).

#pragma once

#include "../utility/windows.h"

namespace ml5 {

                    class  application;
template <typename> class  container;
                    class  event;
template <typename> class  iterator;
                    class  key_event;
                    class  menu_event;
template <typename> struct metainfo;
                    class  metainfo_base;
                    class  metainfo_registry;
                    class  mouse_event;
                    class  object;
                    class  paint_event;
                    class  size_event;
                    class  timer_event;
template <typename> class  value;
template <typename> class  vector;
template <typename> class  vector_iterator;
                    class  window;

namespace impl {

class application;
class canvas;
class frame;

} }   // namespace impl, namespace ml5
