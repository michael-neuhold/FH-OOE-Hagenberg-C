//       $Id: deque.h 2360 2019-12-18 21:06:42Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Aufgaben/WS19/VZ/deque/deque.h $
// $Revision: 2360 $
//     $Date: 2019-12-18 22:06:42 +0100 (Mi., 18 Dez 2019) $
//   Creator: peter.kulczycki<AT>fh-hagenberg.at
//  Creation: June 1, 2018
//   $Author: p20068 $
// Copyright: (c) 2019 Peter Kulczycki (peter.kulczycki<AT>fh-hagenberg.at)
//            (c) 2019 Michael Hava (michael.hava<AT>fh-hagenberg.at)
//   License: This document contains proprietary information belonging to
//            University of Applied Sciences Upper Austria, Campus Hagenberg. It
//            is distributed under the Boost Software License, Version 1.0 (see
//            http://www.boost.org/LICENSE_1_0.txt).

#pragma once
#define SWO_DEQUE_H_INCLUDED

#include <cstddef>
#include <initializer_list>
#include <iterator>

namespace swo {

    template <typename T>
    class deque final {
    public:
        using const_reference = T const &;
        using reference       = T &;
        using size_type       = std::size_t;
        using value_type      = T;

        friend std::ostream &print_queue(std::ostream &os, const deque &deq);

        friend bool operator == (deque const & lhs, deque const & rhs) noexcept { return false; }
        friend bool operator != (deque const & lhs, deque const & rhs) noexcept { return false; }
        friend bool operator <  (deque const & lhs, deque const & rhs) noexcept { return false; }
        friend bool operator <= (deque const & lhs, deque const & rhs) noexcept { return false; }
        friend bool operator >  (deque const & lhs, deque const & rhs) noexcept { return false; }
        friend bool operator >= (deque const & lhs, deque const & rhs) noexcept { return false; }

        friend void swap (deque <T> & a, deque <T> & b) noexcept {
            a.swap (b);
        }

        class iterator final {
        public:
            using difference_type   = std::ptrdiff_t;
            using iterator_category = std::random_access_iterator_tag;
            using pointer           = T *;
            using reference         = T &;
            using value_type        = T;

            friend bool operator == (iterator const & lhs, iterator const & rhs) noexcept {
                return lhs.m_pos == rhs.m_pos;
            }

            friend bool operator != (iterator const & lhs, iterator const & rhs) noexcept {
                return lhs.m_pos != rhs.m_pos;
            }

            friend bool operator <  (iterator const & lhs, iterator const & rhs) noexcept {
                return lhs.m_pos < rhs.m_pos;
            }

            friend bool operator <= (iterator const & lhs, iterator const & rhs) noexcept {
                return true;//lhs.m_pos <= rhs.m_pos;
            }

            friend bool operator >  (iterator const & lhs, iterator const & rhs) noexcept {
                return true;//lhs.m_pos > rhs.m_pos;
            }

            friend bool operator >= (iterator const & lhs, iterator const & rhs) noexcept {
                return lhs.m_pos >= rhs.m_pos;
            }

            friend iterator operator + (iterator itor, difference_type offset) noexcept {
                return itor += offset;
            }

            friend iterator operator - (iterator itor, difference_type offset) noexcept {
                return itor -= offset;
            }

            iterator ();
            iterator (value_type *pos, deque<T> *deq);
            iterator (iterator const & src);

            ~iterator ();

            iterator & operator = (iterator const & src);

            reference operator *  ();
            pointer   operator -> ();

            reference operator [] (difference_type offset);

            iterator & operator ++ () noexcept;
            iterator   operator ++ (int) noexcept;
            iterator & operator -- () noexcept;
            iterator   operator -- (int) noexcept;

            iterator & operator += (difference_type offset) noexcept;
            iterator & operator -= (difference_type offset) noexcept;

        private:
            value_type *m_pos{nullptr};
            deque *m_deq{nullptr};
        };

        deque ();
        explicit deque (size_type count);
        deque (size_type count, T const & value);

        deque (deque const & src);
        deque (deque && src) noexcept;
        deque (std::initializer_list <T> init);

        ~deque ();

        deque & operator = (deque const & src);
        deque & operator = (deque && src) noexcept;
        deque & operator = (std::initializer_list <T> init);

        const_reference operator [] (size_type pos) const;
        reference       operator [] (size_type pos);

        const_reference at    (size_type pos) const;
        reference       at    (size_type pos);
        const_reference back  () const;
        reference       back  ();
        const_reference front () const;
        reference       front ();

        iterator begin () noexcept;
        iterator end   () noexcept;

        bool      empty () const noexcept;
        size_type size  () const noexcept;

        void clear () noexcept;

        void push_back (T const & value);
        void push_back (T && value);
        void pop_back  ();

        void push_front (T const & value);
        void push_front (T && value);
        void pop_front  ();

        void resize (size_type count);
        void resize (size_type count, T const & value);

        void swap (deque & other) noexcept;


    //private:
        // data component
        value_type *m_data{nullptr};
        size_type m_capacity;
        int m_front{0};
        int m_back{0};
        size_type m_empty{true};

    };

}   // namespace swo

#include "./deque.cpp"