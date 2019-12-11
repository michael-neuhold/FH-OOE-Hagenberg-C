//
// Created by Michael Neuhold on 07.12.19.
//

#include "knight.h"

// unicode kings
#define WHITE_BISHOP "\u2658"
#define BLACK_BISHOP "\u265E"

knight::knight(color color) :   m_color{color},
                                m_figure{(color == color::black ? BLACK_BISHOP : WHITE_BISHOP)} {
}

knight::~knight() {
    // nothing to do here
}

color knight::get_color() const {
    return this -> m_color;
}

std::string knight::get_figure() const {
    return this -> m_figure;
}

bool knight::is_essential() const {
    return this -> m_essential;
}

bool knight::possible_move(pos origin, pos target, check_board **cb, int size) const {

    // to do magic

    return true;
}

pos knight::get_position() {
    return m_position;
}

void knight::set_position(pos position) {
    m_position = position;
}

bool knight::get_is_valid() {
    return m_is_valid;
}

void knight::set_is_valid(bool is_valid) {
    m_is_valid = is_valid;
}

std::string knight::get_name() {
    return m_name;
}