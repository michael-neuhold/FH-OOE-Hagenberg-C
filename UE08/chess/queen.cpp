//
// Created by Michael Neuhold on 07.12.19.
//

#include "queen.h"

// unicode queen
#define WHITE_QUEEN "\u2655"
#define BLACK_QUEEN "\u265B"

queen::queen(color color) :   m_color{color},
                              m_figure{(color == color::black ? BLACK_QUEEN : WHITE_QUEEN)} {
}

queen::~queen() {
    // nothing to do here
}

color queen::get_color() const {
    return this -> m_color;
}

std::string queen::get_figure() const {
    return this -> m_figure;
}

bool queen::is_essential() const {
    return this -> m_essential;
}

bool queen::possible_move(pos origin, pos target, check_board **cb, int size) const {

    // to do magic

    return true;
}

pos queen::get_position() {
    return m_position;
}

void queen::set_position(pos position) {
    m_position = position;
}

bool queen::get_is_valid() {
    return m_is_valid;
}

void queen::set_is_valid(bool is_valid) {
    m_is_valid = is_valid;
}

std::string queen::get_name() {
    return m_name;
}