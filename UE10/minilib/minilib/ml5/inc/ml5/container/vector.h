//       $Id: vector.h 607 2019-11-02 22:46:30Z p27116 $
//      $URL: https://svn01.fh-hagenberg.at/se/minilib/ml5/trunk/product/ml5/inc/ml5/container/vector.h $
// $Revision: 607 $
//     $Date: 2019-11-02 23:46:30 +0100 (Sa., 02 Nov 2019) $
//   Creator: michael.hava<AT>fh-hagenberg.at
//  Creation: June 1, 2018
//   $Author: p27116 $
// Copyright: (c) 2018 Michael Hava (michael.hava<AT>fh-hagenberg.at)
//            (c) 2018 Peter Kulczycki (peter.kulczycki<AT>fh-hagenberg.at)
//   License: This document contains proprietary information belonging to
//            University of Applied Sciences Upper Austria, Campus Hagenberg. It
//            is distributed under the Boost Software License, Version 1.0 (see
//            http://www.boost.org/LICENSE_1_0.txt).

#pragma once

#include "./container.h"
#include "./vector_iterator.h"

namespace ml5 {

// -------------------------------------------------------------------------------------------------

template <typename T> class vector final : public container <T>, MI5_DERIVE (vector <T>, container <T>) {
   MI5_INJECT (vector <T>)

   public:
      vector () = default;

      vector (vector const &);
      vector (vector &&) noexcept;

      template <typename U> vector (std::initializer_list <U> const values) {
         grow (std::size (values));

         for (U const & value : values) {
            add (value);
         }
      }

     ~vector() noexcept;

      vector & operator = (vector);

      T &       operator [] (std::size_t idx);
      T const & operator [] (std::size_t idx) const;

      void                           add           (T value) override;
      void                           clear         () noexcept override;
      bool                           contains      (T const & value) const noexcept override;
      std::unique_ptr <iterator <T>> make_iterator () const override;
      void                           remove        (T const & value) noexcept override;
      std::size_t                    size          () const noexcept override;

      T &       at   (std::size_t idx);
      T const & at   (std::size_t idx) const;
      void      swap (vector & other) noexcept;

   private:
      std::size_t find (T const & value) const noexcept;
      void        grow (std::size_t new_capacity = 0);

      std::size_t m_capacity {0};
      std::size_t m_size     {0};
      T *         m_data     {nullptr};
};

template <typename T> vector (std::initializer_list <T>) -> vector <T>;

// -------------------------------------------------------------------------------------------------

template <typename T> constexpr void swap (vector <T> & lhs, vector <T> & rhs) noexcept {
   lhs.swap (rhs);
}

// -------------------------------------------------------------------------------------------------

}   // namespace ml5

#include "./vector.inl"
