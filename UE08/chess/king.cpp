//
// Created by Michael Neuhold on 05.12.19.
//

#include "king.h"

king::king(color color) :   m_color{color},
                            m_figure{(color == color::black? 'k':'K')} {
}

king::~king() {
 // nothing to do here
}

color king::get_color() const {
    return this -> m_color;
}

char king::get_figure() const {
    return this -> m_figure;
}

bool king::is_essential() const {
    return this -> m_essential;
}

bool king::possible_move(pos origin, pos target) const {

    // to do magic

    return true;
}

pos king::get_position() {
    return m_position;
}

void king::set_position(pos position) {
    m_position = position;
}

bool king::get_is_valid() {
    return m_is_valid;
}

void king::set_is_valid(bool is_valid) {
    m_is_valid = is_valid;
}