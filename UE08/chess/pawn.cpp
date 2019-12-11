//
// Created by Michael Neuhold on 07.12.19.
//

#include "pawn.h"


// unicode kings
#define WHITE_PAWN "\u2659"
#define BLACK_PAWN "\u265F"

pawn::pawn(color color) :   m_color{color},
                            m_figure{(color == color::black ? BLACK_PAWN : WHITE_PAWN)} {
}

pawn::~pawn() {
    // nothing to do here
}

color pawn::get_color() const {
    return this -> m_color;
}

std::string pawn::get_figure() const {
    return this -> m_figure;
}

bool pawn::is_essential() const {
    return this -> m_essential;
}

bool pawn::possible_move(pos origin, pos target, check_board **cb, int size) const {
    // pawn kills other character one field cross

    // pawn first move can be two field

    // pawn n-th move can be one field
    /*
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(cb[i][j].is_set) {
                std::cout << cb[i][j].character_name;
            } else {
                std::cout << "****";
            }
        }
        std::cout << std::endl;
    }
     */
    return true;

}

pos pawn::get_position() {
    return m_position;
}

void pawn::set_position(pos position) {
    m_position = position;
}

bool pawn::get_is_valid() {
    return m_is_valid;
}

void pawn::set_is_valid(bool is_valid) {
    m_is_valid = is_valid;
}

std::string pawn::get_name() {
    return m_name;
}