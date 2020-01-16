//       $Id: deque.cpp 2360 2019-12-18 21:06:42Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Aufgaben/WS19/VZ/deque/deque.cpp $
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

#if defined SWO_DEQUE_H_INCLUDED

#include <iostream>
#include <cassert>
#include <exception>
#include "deque.h"


#define INITIAL_SIZE 10
#define ADDITIONAL_SIZE 5

// -------------------------------------------------------------------------------------------------

namespace swo {

// = delete
template <typename T> deque <T>::iterator::iterator () {
}

// mew implemented iterator
template <typename T> deque <T>::iterator::iterator(value_type *pos, deque *deq)
    :   m_pos{pos},
        m_deq{deq} {
}

template <typename T> deque <T>::iterator::iterator (iterator const & src)
    :   m_pos{src.m_pos},
        m_deq{src.m_deq} {
}

template <typename T> deque <T>::iterator::~iterator () {
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator = (iterator const & src) {
    m_pos = src.m_pos;
    m_deq = src.m_deq;
    return *this;
}

template <typename T> typename deque <T>::iterator::reference deque <T>::iterator::operator * () {
   return *m_pos;
}

template <typename T> typename deque <T>::iterator::pointer deque <T>::iterator::operator -> () {
    return *m_pos;
}

template <typename T> typename deque <T>::iterator::reference deque <T>::iterator::operator [] (difference_type offset) {
    return *(*this + offset);
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator ++ () noexcept {
    if(m_pos + 1 < m_deq->m_data + m_deq->m_capacity) {
        ++m_pos;
    } else {
        m_pos = m_deq->m_data;
    }
    return *this;
}

template <typename T> typename deque <T>::iterator deque <T>::iterator::operator ++ (int) noexcept {
    iterator tmp{*this};
    if(m_pos + 1 < m_deq->m_data + m_deq->m_capacity) {
        ++m_pos;
    } else {
        m_pos = m_deq->m_data;
    }
    return tmp;
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator -- () noexcept {
    if(m_pos - 1 >= m_deq->m_data) {
        --m_pos;
    } else  {
        m_pos = m_deq->m_data + m_deq->m_capacity - 1;
    }
    return *this;
}

template <typename T> typename deque <T>::iterator deque <T>::iterator::operator -- (int) noexcept {
    iterator tmp{*this};
    if(m_pos - 1 >= m_deq->m_data) {
        --m_pos;
    } else  {
        m_pos = m_deq->m_data + m_deq->m_capacity - 1;
    }
    return tmp;
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator += (difference_type offset) noexcept {

    if(m_pos + offset < m_deq->m_data + m_deq->m_capacity) {
        m_pos += offset;
    } else {
        int diff = (m_pos + offset) - (m_deq->m_data + m_deq->m_capacity);
        m_pos = m_deq->m_data + diff;
    }
    return *this;
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator -= (difference_type offset) noexcept {

    if(m_pos - offset >= m_deq->m_data) {
        m_pos -= offset;
    } else {
        int diff = m_deq->m_data - (m_pos - offset);
        m_pos = (m_deq->m_data + m_deq->m_capacity) - diff;
    }
    return *this;
}

}   // namespace swo

// -------------------------------------------------------------------------------------------------

namespace swo {

// ---------------------------- CONSTRUCTOR -------------------------------------

template <typename T> deque <T>::deque ()
    :   m_data{new T [INITIAL_SIZE]},
        m_capacity{INITIAL_SIZE} {
    std::cout << "deque constructor" << std::endl;
}

template <typename T> deque <T>::deque (size_type count)
    :   m_data{new T [count]},
        m_capacity{count} {
    std::cout << "deque constructor with size" << std::endl;
}

template <typename T> deque <T>::deque (size_type count, T const & value)
    :   m_data{new T [count]},
        m_capacity{count} {
    std::cout << "deque constructor with size, data element" << std::endl;
    for(size_type i = 0; i < count; i++){
        push_back(value);
    }

}

template <typename T> deque <T>::deque (deque const & src)
    :   m_data{new T [src.size()]},
        m_capacity{src.size()},
        m_back{src.m_back},         // getter
        m_front{src.m_front},       // getter
        m_empty{src.m_empty} {
    std::cout << "deque constructor copy" << std::endl;
    for(size_type i = 0; i < src.size(); i++) {
        m_data[i] = src.m_data[i];
    }
}

template <typename T> deque <T>::deque (deque && src) noexcept
    :   m_data{src.m_data},
        m_capacity{src.size()},
        m_back{src.m_back},         // getter
        m_front{src.m_front},       // getter
        m_empty{src.m_empty} {      // getter
    std::cout << "constructor move" << std::endl;
    src.m_data = nullptr;
    src.m_capacity = 0;
    src.m_back = 0;
    src.m_front = 0;
}

template <typename T> deque <T>::deque (std::initializer_list <T> init)
    :   m_data{new T [init.size()]},
        m_capacity{init.size()} {
    std::cout << "deque constructor initializer_list" << std::endl;
    for(size_type i = 0; i < init.size(); i++) {
        push_back(init.begin()[i]);
    }
}

template <typename T> deque <T>::~deque () {
    delete [] m_data;
}

template <typename T> deque <T> & deque <T>::operator = (deque const & src) {
    delete [] m_data;
    m_capacity = src.m_capacity;
    m_front = src.m_front;
    m_back = src.m_back;
    m_empty = src.m_empty;
    m_data = new T [m_capacity];
    for(size_type i = 0; i < src.size(); i++) {
        m_data[i] = src.m_data[i];
    }
    return *this;
}

template <typename T> deque <T> & deque <T>::operator = (deque && src) noexcept {
    delete [] m_data;
    m_capacity = src.m_capacity;
    m_front = src.m_front;
    m_back = src.m_back;
    m_data = src.m_data;
    src.m_data = nullptr;
    return *this;
    // return *src;
}

template <typename T> deque <T> & deque <T>::operator = (std::initializer_list <T> init) {
    delete [] m_data;
    m_capacity = init.size();
    m_data = new T [m_capacity];
    for(size_type i = 0; i < init.size(); i++) {
        push_back(init.begin()[i]);
    }
    return *this;
}

template <typename T> typename deque <T>::const_reference deque <T>::operator [] (size_type pos) const {
    iterator tmp_begin  = begin();
    iterator tmp_end    = end();

    tmp_begin += pos;

    if(tmp_begin > tmp_end){
        throw std::range_error("range error occured!");
    }

    return *tmp_begin;
}

template <typename T> typename deque <T>::reference deque <T>::operator [] (size_type pos) {
    iterator tmp_begin  = begin();
    iterator tmp_end    = end();

    tmp_begin += pos;

    if(tmp_begin > tmp_end){
        throw std::range_error("range error occured!");
    }

    return *tmp_begin;
}

template <typename T> typename deque <T>::const_reference deque <T>::at (size_type pos) const {
    iterator tmp_begin  = begin();
    iterator tmp_end    = end();

    tmp_begin += pos;

    if(tmp_begin > tmp_end){
        throw std::range_error("range error occured!");
    }

    return *tmp_begin;
}

template <typename T> typename deque <T>::reference deque <T>::at (size_type pos) {
    iterator tmp_begin  = begin();
    iterator tmp_end    = end();

    tmp_begin += pos;

    if(tmp_begin > tmp_end){
        throw std::range_error("range error occured!");
    }

    return *tmp_begin;
}

template <typename T> typename deque <T>::const_reference deque <T>::back () const {
    return m_data[m_back];
}

template <typename T> typename deque <T>::reference deque <T>::back () {
    return m_data[m_back];
}

template <typename T> typename deque <T>::const_reference deque <T>::front () const {
    return m_data[m_front];
}

template <typename T> typename deque <T>::reference deque <T>::front () {
    return m_data[m_front];
}

template <typename T> typename deque <T>::iterator deque <T>::begin () noexcept {
   return iterator(m_data + m_front, this);
}

template <typename T> typename deque <T>::iterator deque <T>::end () noexcept {
   return iterator(m_data + m_back + 1, this);
}

template <typename T> bool deque <T>::empty () const noexcept {
   return m_empty;
}

template <typename T> typename deque <T>::size_type deque <T>::size () const noexcept {
    if(m_empty) return 0;
    auto tmp_begin  = const_cast<swo::deque<value_type>*>(this) -> begin();
    auto tmp_end    = const_cast<swo::deque<value_type>*>(this) -> end();
    size_type count = 0;
    while(tmp_begin != tmp_end) {
        tmp_begin++;
        count++;
    }
    return count;
}

template <typename T> void deque <T>::clear () noexcept {
    m_empty = true;
    m_front = 0;
    m_back = 0;
}

template <typename T> void deque <T>::push_back (T const & value) {
    if(m_capacity == size()) {
        std::cout << "test";
        resize(m_capacity + ADDITIONAL_SIZE);
    }
    if(m_empty) {
        m_data[m_back] = value;
        m_empty = false;
    } else {
        if(m_back > m_capacity - 1) {
            m_back = 0;
            m_data[m_back] = value;
        } else {
            m_back++;
            m_data[m_back] = value;
        }
    }

}

template <typename T> void deque <T>::push_back (T && value) {
    if(m_capacity == size()) {
        std::cout << "test";
        resize(m_capacity + ADDITIONAL_SIZE);
    }
    if(m_empty) {
        m_data[m_back] = value;
        m_empty = false;
    } else {
        if(m_back > m_capacity - 1) {
            m_back = 0;
            m_data[m_back] = value;
        } else {
            m_back++;
            m_data[m_back] = value;
        }
    }
}

template <typename T> void deque <T>::pop_back () {
    if(m_capacity == size()) resize(m_capacity + ADDITIONAL_SIZE);
    if(size() == 0) return;
    if(size() == 1) {
        m_empty = true;
    } else {
        if(m_back - 1 < 0) {
            m_back = m_data + m_capacity - 1;
        } else {
            m_back--;
        }
    }
}

template <typename T> void deque <T>::push_front (T const & value) {
    if(m_capacity == size()) resize(m_capacity + ADDITIONAL_SIZE);
    if(m_empty) {
        m_data[m_back] = value;
        m_empty = false;
    } else {
        if(m_front < 0) {
            m_front = m_data + m_capacity - 1;
            m_data[m_front] = value;
        } else {
            m_front--;
            m_data[m_front] = value;
        }
    }
}

template <typename T> void deque <T>::push_front (T && value) {
   if(m_capacity == size()) resize(m_capacity + ADDITIONAL_SIZE);
    if(m_empty) {
        m_data[m_back] = value;
        m_empty = false;
    } else {
        if(m_front < 0) {
            m_front = m_capacity - 1;
            m_data[m_front] = value;
        } else {
            m_front--;
            m_data[m_front] = value;
        }
    }
}

template <typename T> void deque <T>::pop_front () {
    if(size() == 0) return;
    if(size() == 1) {
        m_empty = true;
    } else {
        if(m_front + 1 == m_capacity) {
            m_front = m_data;
        } else {
            m_front++;
        }
    }
}

template <typename T> void deque <T>::resize (size_type count) {
    std::cout << "resize";
    T *new_data = new T [count];
    int cnt = -1;

    iterator tmp_begin = begin();
    iterator end_limit = tmp_begin;

    end_limit += (m_capacity > count ? count : m_capacity);

    for(swo::deque<int>::iterator p = tmp_begin;p != end_limit;p++) {
        new_data[cnt] = *p;
        cnt++;
    }

    delete [] m_data;
    m_front = 0;
    m_back = cnt;
    m_capacity = count;
    m_data = new_data;
}

template <typename T> void deque <T>::resize (size_type count, T const & value) {
    resize(count);
    push_back(value);
}

template <typename T> void deque <T>::swap (deque & other) noexcept {
    deque tmp(other);
    other = *this;
    *this = tmp;
}

}   // namespace swo

// -------------------------------------------------------------------------------------------------

#endif   // SWO_DEQUE_H_INCLUDED