//
// Created by Michael Neuhold on 07.12.19.
//

#include "knight.h"
#include "./characters.h"


/*----------------------------------------------------------------------------*/

knight::knight(color color) :   m_color{color},
                                m_figure{(color == color::black ? BLACK_BISHOP : WHITE_BISHOP)} {
}

/*----------------------------------------------------------------------------*/

knight::~knight() {
    // nothing to do here
}

/*----------------------------------------------------------------------------*/

color knight::get_color() const {
    return this -> m_color;
}

/*----------------------------------------------------------------------------*/

std::string knight::get_figure() const {
    return this -> m_figure;
}

/*----------------------------------------------------------------------------*/

bool knight::is_essential() const {
    return this -> m_essential;
}

/*----------------------------------------------------------------------------*/

std::string knight::get_name() const {
    return m_name;
}

/*----------------------------------------------------------------------------*/

void knight::set_first_move_done(bool moved) {
    m_first_move_done = moved;
}

/*----------------------------------------------------------------------------*/

void knight::calc_all_possible_moves(pos origin, check_board **cb, const int size) {

    int coordinate_change_x[] = { 2 , 1 , -1 , -2 , -2 , -1 , 1 , 2 };
    int coordinate_change_y[] = { 1 , 2 , 2 , 1 , -1 , -2 , -2 , -1 };

    int tmp_x;
    int tmp_y;

    color target_color = (cb[origin.x][origin.y].color == color::white ? color::black : color::white);

    for(int i = 0; i < 8; i++) {
        tmp_x = origin.x + coordinate_change_x[i];
        tmp_y = origin.y + coordinate_change_y[i];
        if(tmp_x < size && tmp_x >= 0 && tmp_y < size && tmp_y >= 0) {
            if(!cb[tmp_x][tmp_y].is_set) {
                cb[tmp_x][tmp_y].moveable = true;
            } else if (cb[tmp_x][tmp_y].color == target_color){
                cb[tmp_x][tmp_y].killable = true;
            }
        }
    }
}
