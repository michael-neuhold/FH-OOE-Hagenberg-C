//
// Created by Michael Neuhold on 05.12.19.
//

#include "king.h"
#include "./characters.h"


/*----------------------------------------------------------------------------*/

king::king(color color) :   m_color{color},
                            m_figure{(color == color::black ? BLACK_KING : WHITE_KING)} {
}

/*----------------------------------------------------------------------------*/

king::~king() {
 // nothing to do here
}

/*----------------------------------------------------------------------------*/

color king::get_color() const {
    return this -> m_color;
}

/*----------------------------------------------------------------------------*/

std::string king::get_figure() const {
    return this -> m_figure;
}

/*----------------------------------------------------------------------------*/

bool king::is_essential() const {
    return this -> m_essential;
}

/*----------------------------------------------------------------------------*/

std::string king::get_name() const {
    return m_name;
}

/*----------------------------------------------------------------------------*/

void king::set_first_move_done(bool moved) {
    m_first_move_done = moved;
}

/*----------------------------------------------------------------------------*/

void king::calc_all_possible_moves(pos origin, check_board **cb, const int size) {

    color target_color = (cb[origin.x][origin.y].color == color::white ? color::black : color::white);

    int coordinate_change_x[] = { 1 , 1 , 0 , -1 , -1 , -1 , 0 , 1 };
    int coordinate_change_y[] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 };

    int tmp_x;
    int tmp_y;

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
