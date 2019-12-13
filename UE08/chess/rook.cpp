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

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
bool rook::possible_move(pos origin, pos target, check_board **cb, int size) const {

    /*
     *  TODO possible_move rook
     */

    return true;
}

void rook::calc_all_possible_moves(pos origin, check_board **cb, int size) {

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
                case 0: tmp_x++; break;
                case 1: tmp_x--; break;
                case 2: tmp_y--; break;
                case 3: tmp_y++; break;
            }

            if(tmp_x < size && tmp_x >= 0 && tmp_y < size && tmp_y >= 0) {
                if (!cb[tmp_x][tmp_y].is_set) {
                    cb[tmp_x][tmp_y].moveable = true;
                } else if (cb[tmp_x][tmp_y].color == target_color) {
                    cb[tmp_x][tmp_y].killable = true;
                    collision = true;
                }
            }
        }
    }
    /*
    int tmp_origin_x = origin.x;
    int tmp_origin_y = origin.y;

    color target_color = (cb[origin.x][origin.y].color == color::white ? color::black : color::white);

    bool collision{false};

    tmp_origin_x--;
    while(tmp_origin_x >= 0 && !collision) {

        if(!cb[tmp_origin_x][tmp_origin_y].is_set) {
            cb[tmp_origin_x][tmp_origin_y].moveable = true;
        } else if (cb[tmp_origin_x][tmp_origin_y].color == target_color){
            cb[tmp_origin_x][tmp_origin_y].killable = true;
            collision = true;
        }
        tmp_origin_x--;
    }

    tmp_origin_x = origin.x;
    tmp_origin_x++;
    collision = false;
    while(tmp_origin_x < size && !collision) {

        if(!cb[tmp_origin_x][tmp_origin_y].is_set) {
            cb[tmp_origin_x][tmp_origin_y].moveable = true;
        } else if (cb[tmp_origin_x][tmp_origin_y].color == target_color){
            cb[tmp_origin_x][tmp_origin_y].killable = true;
            collision = true;
        }
        tmp_origin_x++;
    }

    tmp_origin_x = origin.x;
    tmp_origin_y = origin.y;
    collision = false;
    tmp_origin_y--;
    while(tmp_origin_y >= 0 && !collision) {

        if(!cb[tmp_origin_x][tmp_origin_y].is_set) {
            cb[tmp_origin_x][tmp_origin_y].moveable = true;
        } else if (cb[tmp_origin_x][tmp_origin_y].color == target_color){
            cb[tmp_origin_x][tmp_origin_y].killable = true;
            collision = true;
        }
        tmp_origin_y--;
    }

    tmp_origin_x = origin.x;
    tmp_origin_y = origin.y;
    collision = false;
    tmp_origin_y++;
    while(tmp_origin_y < size && !collision) {

        if(!cb[tmp_origin_x][tmp_origin_y].is_set) {
            cb[tmp_origin_x][tmp_origin_y].moveable = true;
        } else if (cb[tmp_origin_x][tmp_origin_y].color == target_color){
            cb[tmp_origin_x][tmp_origin_y].killable = true;
            collision = true;
        }
        tmp_origin_y++;
    }
*/
}

/*----------------------------------------------------------------------------*/

bool rook::get_is_valid() {
    return m_is_valid;
}

void rook::set_is_valid(bool is_valid) {
    m_is_valid = is_valid;
}

std::string rook::get_name() {
    return m_name;
}