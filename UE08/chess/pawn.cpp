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

    // check if first move of pawn than 2 steps possible // otherwise 1 step possible
    int possible_moves = m_first_move_done ? 1 : 2;

    // return if target
    if(cb[target.x][target.y].is_set) return false;

    int offset;
    while(possible_moves > 0) {
        offset = (cb[origin.x][origin.y].color == color::white ? possible_moves * (-1) : possible_moves );
        if(origin.x + offset == target.x && origin.y == target.y) {
            cb[target.x][target.y].moveable = true;
            return true;
        }
        possible_moves--;
    }
    return false;
}

void pawn::calc_all_possible_moves(pos origin, check_board **cb, int size) {

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