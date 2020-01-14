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
#include "deque.h"


#define INITIAL_SIZE 10

// -------------------------------------------------------------------------------------------------

namespace swo {

template <typename T> deque <T>::iterator::iterator () {
}

template <typename T> deque <T>::iterator::iterator (iterator const & src) {
}

template <typename T> deque <T>::iterator::~iterator () {
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator = (iterator const & src) {
   return *this;
}

template <typename T> typename deque <T>::iterator::reference deque <T>::iterator::operator * () {
   return *m_pos;
}

template <typename T> typename deque <T>::iterator::pointer deque <T>::iterator::operator -> () {
    return *m_pos;
}

template <typename T> typename deque <T>::iterator::reference deque <T>::iterator::operator [] (difference_type offset) {
    // range check
    // set m_pos = offset
    // return *m_pos;
    return {};
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator ++ () noexcept {
    ++m_pos;
    return *this;
}

template <typename T> typename deque <T>::iterator deque <T>::iterator::operator ++ (int) noexcept {
   iterator tmp{*this};
    ++m_pos;
    return tmp;
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator -- () noexcept {
    --m_pos;
    return *this;
}

template <typename T> typename deque <T>::iterator deque <T>::iterator::operator -- (int) noexcept {
    iterator tmp{*this};
    --m_pos;
    return tmp;
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator += (difference_type offset) noexcept {
    m_pos += offset;
    return *this;
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator -= (difference_type offset) noexcept {
    m_pos += offset;
    return *this;
}

}   // namespace swo

// -------------------------------------------------------------------------------------------------

namespace swo {

// ---------------------------- CONSTRUCTOR -------------------------------------

template <typename T> deque <T>::deque () : m_data{new T [INITIAL_SIZE]}, m_capacity{INITIAL_SIZE} {
    std::cout << "constructor with 0 Parameters" << std::endl;
}

template <typename T> deque <T>::deque (size_type count) : m_data{new T [count]}, m_capacity{count} {
    std::cout << "constructor with 1<int> Parameters" << std::endl;
}

template <typename T> deque <T>::deque (size_type count, T const & value)
    :   m_data{new T [count]},
        m_capacity{count} {

    std::cout << "constructor with size<int> and one data element" << std::endl;

    // init all elements with value
    for(size_type i = 0; i < count; i++) {
        push_back(value);
    }
}

template <typename T> deque <T>::deque (deque const & src)
    :   m_data{new T [src.size()]},
        m_capacity{src.m_capacity},
        m_back{src.m_back},
        m_front{src.m_front} {

    std::cout << "constructor copy" << std::endl;
    for(size_type i = 0; i <= src.m_back; i++) {
        m_data[i] = src.m_data[i];
    }
}

template <typename T> deque <T>::deque (deque && src) noexcept
    :   m_data{src.m_data},
        m_capacity{src.m_capacity},
        m_back{src.m_back},
        m_front{src.m_front},
        m_empty{src.m_empty}{

    std::cout << "constructor move" << std::endl;
    //src.m_data = nullptr;
    //src.m_capacity = 0;
}

template <typename T> deque <T>::deque (std::initializer_list <T> init) : m_data{new T [init.size()]}, m_capacity{init.size()} {
    std::cout << "constructor with initializer list" << std::endl;
    for(size_type i = 0; i < init.size(); i++) {
        //m_data[i] = init.begin()[i];
        push_back(init.begin()[i]);
        //std::cout << "value: " << init.begin()[i] << std::endl;
    }
}

template <typename T> deque <T>::~deque () {
    delete [] m_data;
}

template <typename T> deque <T> & deque <T>::operator = (deque const & src) {
    assert(m_capacity >= src.m_capacity);
    for(size_type i = 0; i < src.m_capacity; i++) {
        m_data[i] = std::move(src.m_data[i]);
    }
    return *this;
}

template <typename T> deque <T> & deque <T>::operator = (deque && src) noexcept {
    // delete [] m_data;
    m_data = src.m_data;
    m_capacity = src.m_capacity;
    src.m_data = nullptr;
    src.m_capacity = 0;
    return *this;
}

template <typename T> deque <T> & deque <T>::operator = (std::initializer_list <T> init) {
    // delete [] m_data;
    if(init.size() > m_capacity) {
        resize(init.size());
        m_capacity = init.size();
    }
    for(int i = 0; i < init.size(); i++) {
        m_data[i] = init.begin()[i];
        std::cout << "value: " << m_data[i] << std::endl;
    }
    return *this;
}

template <typename T> typename deque <T>::const_reference deque <T>::operator [] (size_type pos) const {
    // range check
    return m_data[pos];
}

template <typename T> typename deque <T>::reference deque <T>::operator [] (size_type pos) {
    // range check
    return m_data[pos];
}

template <typename T> typename deque <T>::const_reference deque <T>::at (size_type pos) const {
    // range check
    return m_data[pos];
}

template <typename T> typename deque <T>::reference deque <T>::at (size_type pos) {
    // range check
    return m_data[pos];
}

template <typename T> typename deque <T>::const_reference deque <T>::back () const {
    // range check
    return m_data[m_back];
}

template <typename T> typename deque <T>::reference deque <T>::back () {
    // range check
    return m_data[m_back];
}

template <typename T> typename deque <T>::const_reference deque <T>::front () const {
    // range check
    return m_data[m_front];
}

template <typename T> typename deque <T>::reference deque <T>::front () {
    // range check
    return m_data[m_front];
}

template <typename T> typename deque <T>::iterator deque <T>::begin () noexcept {
   return iterator(m_data);
}

template <typename T> typename deque <T>::iterator deque <T>::end () noexcept {
    // circular ??
   return iterator(m_data);
}

template <typename T> bool deque <T>::empty () const noexcept {
   return true;
}

template <typename T> typename deque <T>::size_type deque <T>::size () const noexcept {
   return m_capacity;
}

template <typename T> void deque <T>::clear () noexcept {
    delete [] m_data;
    m_data = nullptr;
    // set size diff between front and back to 0
}

template <typename T> void deque <T>::push_back (T const & value) {
    //std::cout << "current_back: " << m_back << std::endl;
    //std::cout << "insert value: " << value << std::endl;
    if(m_empty) {
        m_data[m_back] = value;
        m_empty = false;
    } else {
        if(m_back + 1 < m_capacity) {
            m_back++;
            m_data[m_back] = value;
        }
    }

}

template <typename T> void deque <T>::push_back (T && value) {
    //std::cout << "current_back: " << m_back << std::endl;
    //std::cout << "insert value: " << value << std::endl;
    if(m_empty) {
        m_data[m_back] = value;
        m_empty = false;
    } else {
        if(m_back + 1 < m_capacity) {
            m_back++;
            m_data[m_back] = value;
        }
    }
}

template <typename T> void deque <T>::pop_back () {
    // delete element from back position
}

template <typename T> void deque <T>::push_front (T const & value) {
}

template <typename T> void deque <T>::push_front (T && value) {
}

template <typename T> void deque <T>::pop_front () {
    // delete element from front position
}

template <typename T> void deque <T>::resize (size_type count) {
    assert(count > m_capacity);
    T *new_data = new T [count];
    for(size_type i = 0; i < m_capacity; i++) {
        new_data[i] = std::move(m_data[i]);
    }
    delete [] m_data;
    m_data = new_data;
}

template <typename T> void deque <T>::resize (size_type count, T const & value) {
    resize(count);
    // push back(value);
}

template <typename T> void deque <T>::swap (deque & other) noexcept {
}

}   // namespace swo

// -------------------------------------------------------------------------------------------------

#endif   // SWO_DEQUE_H_INCLUDED