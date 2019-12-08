//
// Created by Michael Neuhold on 07.12.19.
//

#include "rook.h"


// unicode kings
#define WHITE_BISHOP "\u2656"
#define BLACK_BISHOP "\u265C"

rook::rook(color color) :   m_color{color},
                            m_figure{(color == color::black ? BLACK_BISHOP : WHITE_BISHOP)} {
}

rook::~rook() {
    // nothing to do here
}

color rook::get_color() const {
    return this -> m_color;
}

std::string rook::get_figure() const {
    return this -> m_figure;
}

bool rook::is_essential() const {
    return this -> m_essential;
}

bool rook::possible_move(pos origin, pos target) const {

    // to do magic

    return true;
}

pos rook::get_position() {
    return m_position;
}

void rook::set_position(pos position) {
    m_position = position;
}

bool rook::get_is_valid() {
    return m_is_valid;
}

void rook::set_is_valid(bool is_valid) {
    m_is_valid = is_valid;
}

std::string rook::get_name() {
    return m_name;
}