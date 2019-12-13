//
// Created by Michael Neuhold on 07.12.19.
//

#include "pawn.h"


// unicode pawn
#define WHITE_PAWN "\u2659"
#define BLACK_PAWN "\u265F"

/*----------------------------------------------------------------------------*/

pawn::pawn(color color) :   m_color{color},
                            m_figure{(color == color::black ? BLACK_PAWN : WHITE_PAWN)} {
}

/*----------------------------------------------------------------------------*/

pawn::~pawn() {
    // nothing to do here
}

/*----------------------------------------------------------------------------*/

color pawn::get_color() const {
    return this -> m_color;
}

/*----------------------------------------------------------------------------*/

std::string pawn::get_figure() const {
    return this -> m_figure;
}

/*----------------------------------------------------------------------------*/

bool pawn::is_essential() const {
    return this -> m_essential;
}

/*----------------------------------------------------------------------------*/

bool pawn::possible_move(pos origin, pos target, check_board **cb, int size) const {

    /*
     *  TODO possible_move pawn
     */

    return true;
}

/*----------------------------------------------------------------------------*/

void pawn::calc_all_possible_moves(pos origin, check_board **cb, int size) {

    color target_color = (cb[origin.x][origin.y].color == color::white ? color::black : color::white);

    int direction = (cb[origin.x][origin.y].color == color::white ? -1 : 1);
    int tmp_x;
    int tmp_y;

    /* ---- moves ---- */

    int coordinates_move_x[] = { origin.x + direction   , origin.x + 2 * direction  };
    int coordinates_move_y[] = { origin.y               , origin.y                  };

    int move_limit = (m_first_move_done ? 1 : 2);
    for(int i = 0; i < move_limit; i++) {
        tmp_x = coordinates_move_x[i];
        tmp_y = coordinates_move_y[i];
        if( tmp_x < size && tmp_x >= 0 && tmp_y < size && tmp_y >= 0) {
            if(!cb[tmp_x][tmp_y].is_set) {
                cb[tmp_x][tmp_y].moveable = true;
            }
        }
    }

    /* ---- kills ---- */

    int coordinates_kill_x[] = { origin.x + direction   , origin.x + direction  };
    int coordinates_kill_y[] = { origin.y - 1           , origin.y + 1          };

    for(int i = 0; i < 2; i++) {
        tmp_x = coordinates_kill_x[i];
        tmp_y = coordinates_kill_y[i];
        if( tmp_x < size && tmp_x >= 0 && tmp_y < size && tmp_y >= 0) {
            if(cb[tmp_x][tmp_y].color == target_color) {
                cb[tmp_x][tmp_y].killable = true;
            }
        }
    }
}

/*----------------------------------------------------------------------------*/

bool pawn::get_is_valid() {
    return m_is_valid;
}

/*----------------------------------------------------------------------------*/

void pawn::set_is_valid(bool is_valid) {
    m_is_valid = is_valid;
}

/*----------------------------------------------------------------------------*/

std::string pawn::get_name() {
    return m_name;
}

/*----------------------------------------------------------------------------*/

void pawn::set_first_move_done(bool moved) {
    m_first_move_done = moved;
}