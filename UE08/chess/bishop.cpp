//
// Created by Michael Neuhold on 07.12.19.
//

#include "bishop.h"

// unicode kings
#define WHITE_BISHOP "\u2657"
#define BLACK_BISHOP "\u265D"

bishop::bishop(color color) :   m_color{color},
                                m_figure{(color == color::black ? BLACK_BISHOP : WHITE_BISHOP)} {
}

bishop::~bishop() {
    // nothing to do here
}

color bishop::get_color() const {
    return this -> m_color;
}

std::string bishop::get_figure() const {
    return this -> m_figure;
}

bool bishop::is_essential() const {
    return this -> m_essential;
}

bool bishop::possible_move(pos origin, pos target) const {

    // to do magic

    return true;
}

pos bishop::get_position() {
    return m_position;
}

void bishop::set_position(pos position) {
    m_position = position;
}

bool bishop::get_is_valid() {
    return m_is_valid;
}

void bishop::set_is_valid(bool is_valid) {
    m_is_valid = is_valid;
}

std::string bishop::get_name() {
    return m_name;
}