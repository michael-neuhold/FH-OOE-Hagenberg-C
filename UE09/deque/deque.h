//
// Created by Michael Neuhold on 19.12.19.
//

#pragma once

#include <cstddef>
#include <initializer_list>
#include <iterator>

namespace swo {

    template <typename T> class deque final {
    public:
        using const_reference = T const &;
        using reference       = T &;
        using size_type       = std::size_t;
        using value_type      = T;

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

            friend bool operator == (iterator const & lhs, iterator const & rhs) noexcept { return false; }
            friend bool operator != (iterator const & lhs, iterator const & rhs) noexcept { return false; }
            friend bool operator <  (iterator const & lhs, iterator const & rhs) noexcept { return false; }
            friend bool operator <= (iterator const & lhs, iterator const & rhs) noexcept { return false; }
            friend bool operator >  (iterator const & lhs, iterator const & rhs) noexcept { return false; }
            friend bool operator >= (iterator const & lhs, iterator const & rhs) noexcept { return false; }

            friend iterator operator + (iterator itor, difference_type offset) noexcept {
                return itor += offset;
            }

            friend iterator operator - (iterator itor, difference_type offset) noexcept {
                return itor -= offset;
            }

            iterator ();
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
    };

}   // namespace swo



