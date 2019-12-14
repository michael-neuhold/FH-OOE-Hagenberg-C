//
// Created by Michael Neuhold on 07.12.19.
//

#include "queen.h"
#include "./characters.h"


/*----------------------------------------------------------------------------*/

queen::queen(color color) :   m_color{color},
                              m_figure{(color == color::black ? BLACK_QUEEN : WHITE_QUEEN)} {
}

/*----------------------------------------------------------------------------*/

queen::~queen() {
    // nothing to do here
}

/*----------------------------------------------------------------------------*/

color queen::get_color() const {
    return this -> m_color;
}

/*----------------------------------------------------------------------------*/

std::string queen::get_figure() const {
    return this -> m_figure;
}

/*----------------------------------------------------------------------------*/

bool queen::is_essential() const {
    return this -> m_essential;
}

/*----------------------------------------------------------------------------*/

std::string queen::get_name() const {
    return m_name;
}

/*----------------------------------------------------------------------------*/

void queen::set_first_move_done(bool moved) {
    m_first_move_done = moved;
}

/*----------------------------------------------------------------------------*/

void queen::calc_all_possible_moves(pos origin, check_board **cb, const int size) {
    int tmp_x;
    int tmp_y;

    bool collision;

    color target_color = (cb[origin.x][origin.y].color == color::white ? color::black : color::white);

    for(int i = 0; i < 8; i++) {
        collision = false;
        tmp_x = origin.x;
        tmp_y = origin.y;

        while(tmp_x < size && tmp_x >= 0 && tmp_y < size && tmp_y >= 0 && !collision) {
            switch (i) {
                case 0: tmp_x++; tmp_y--; break;
                case 1: tmp_x--; tmp_y++; break;
                case 2: tmp_x--; tmp_y--; break;
                case 3: tmp_x++; tmp_y++; break;
                case 4: tmp_x++; break;
                case 5: tmp_x--; break;
                case 6: tmp_y--; break;
                case 7: tmp_y++; break;
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
