//
// Created by Michael Neuhold on 07.12.19.
//

#include "bishop.h"

#include "./characters.h"

/*----------------------------------------------------------------------------*/

bishop::bishop(color color) :   m_color{color},
                                m_figure{(color == color::black ? BLACK_BISHOP : WHITE_BISHOP)} {
}

/*----------------------------------------------------------------------------*/

bishop::~bishop() {
    // nothing to do here
}

/*----------------------------------------------------------------------------*/

color bishop::get_color() const {
    return this -> m_color;
}

/*----------------------------------------------------------------------------*/

std::string bishop::get_figure() const {
    return this -> m_figure;
}

/*----------------------------------------------------------------------------*/

bool bishop::is_essential() const {
    return this -> m_essential;
}

/*----------------------------------------------------------------------------*/

std::string bishop::get_name() const {
    return m_name;
}

/*----------------------------------------------------------------------------*/

void bishop::set_first_move_done(bool moved) {
    m_first_move_done = moved;
}

/*----------------------------------------------------------------------------*/

void bishop::calc_all_possible_moves(pos origin, check_board **cb, const int size) {

    int tmp_x;
    int tmp_y;

    bool collision;

    color target_color = (cb[origin.x][origin.y].color == color::white ? color::black : color::white);

    for(int i = 0; i < 4; i++) {
        collision = false;
        tmp_x = origin.x;
        tmp_y = origin.y;

        while(tmp_x < size && tmp_x >= 0 && tmp_y < size && tmp_y >= 0 && !collision) {
            switch (i) {
                case 0: tmp_x++; tmp_y--; break;
                case 1: tmp_x--; tmp_y++; break;
                case 2: tmp_x--; tmp_y--; break;
                case 3: tmp_x++; tmp_y++; break;
            }

            if(tmp_x < size && tmp_x >= 0 && tmp_y < size && tmp_y >= 0) {
                if (!cb[tmp_x][tmp_y].is_set) {
                    cb[tmp_x][tmp_y].moveable = true;
                } else if (cb[tmp_x][tmp_y].color == cb[origin.x][origin.y].color) {
                    collision = true;
                } else if (cb[tmp_x][tmp_y].color == target_color) {
                    cb[tmp_x][tmp_y].killable = true;
                    collision = true;
                }
            }
        }

    }
}
