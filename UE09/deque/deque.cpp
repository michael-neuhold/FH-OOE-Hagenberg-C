//
// Created by Michael Neuhold on 19.12.19.
//

#include "./deque.h"

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
   return {};
}

template <typename T> typename deque <T>::iterator::pointer deque <T>::iterator::operator -> () {
   return {};
}

template <typename T> typename deque <T>::iterator::reference deque <T>::iterator::operator [] (difference_type offset) {
   return {};
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator ++ () noexcept {
   return {};
}

template <typename T> typename deque <T>::iterator deque <T>::iterator::operator ++ (int) noexcept {
   return {};
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator -- () noexcept {
   return {};
}

template <typename T> typename deque <T>::iterator deque <T>::iterator::operator -- (int) noexcept {
   return {};
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator += (difference_type offset) noexcept {
   return {};
}

template <typename T> typename deque <T>::iterator & deque <T>::iterator::operator -= (difference_type offset) noexcept {
   return {};
}

}   // namespace swo

// -------------------------------------------------------------------------------------------------

namespace swo {

template <typename T> deque <T>::deque () {
}

template <typename T> deque <T>::deque (size_type count) {
}

template <typename T> deque <T>::deque (size_type count, T const & value) {
}

template <typename T> deque <T>::deque (deque const & src) {
}

template <typename T> deque <T>::deque (deque && src) noexcept {
}

template <typename T> deque <T>::deque (std::initializer_list <T> init) {
}

template <typename T> deque <T>::~deque () {
}

template <typename T> deque <T> & deque <T>::operator = (deque const & src) {
   return *this;
}

template <typename T> deque <T> & deque <T>::operator = (deque && src) noexcept {
   return *this;
}

template <typename T> deque <T> & deque <T>::operator = (std::initializer_list <T> init) {
   return *this;
}

template <typename T> typename deque <T>::const_reference deque <T>::operator [] (size_type pos) const {
   return {};
}

template <typename T> typename deque <T>::reference deque <T>::operator [] (size_type pos) {
   return {};
}

template <typename T> typename deque <T>::const_reference deque <T>::at (size_type pos) const {
   return {};
}

template <typename T> typename deque <T>::reference deque <T>::at (size_type pos) {
   return {};
}

template <typename T> typename deque <T>::const_reference deque <T>::back () const {
   return {};
}

template <typename T> typename deque <T>::reference deque <T>::back () {
   return {};
}

template <typename T> typename deque <T>::const_reference deque <T>::front () const {
   return {};
}

template <typename T> typename deque <T>::reference deque <T>::front () {
   return {};
}

template <typename T> typename deque <T>::iterator deque <T>::begin () noexcept {
   return {};
}

template <typename T> typename deque <T>::iterator deque <T>::end () noexcept {
   return {};
}

template <typename T> bool deque <T>::empty () const noexcept {
   return true;
}

template <typename T> typename deque <T>::size_type deque <T>::size () const noexcept {
   return {};
}

template <typename T> void deque <T>::clear () noexcept {
}

template <typename T> void deque <T>::push_back (T const & value) {
}

template <typename T> void deque <T>::push_back (T && value) {
}

template <typename T> void deque <T>::pop_back () {
}

template <typename T> void deque <T>::push_front (T const & value) {
}

template <typename T> void deque <T>::push_front (T && value) {
}

template <typename T> void deque <T>::pop_front () {
}

template <typename T> void deque <T>::resize (size_type count) {
}

template <typename T> void deque <T>::resize (size_type count, T const & value) {
}

template <typename T> void deque <T>::swap (deque & other) noexcept {
}

}   // namespace swo

// -------------------------------------------------------------------------------------------------

#endif   // SWO_DEQUE_H_INCLUDED
