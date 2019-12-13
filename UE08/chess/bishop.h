//
// Created by Michael Neuhold on 07.12.19.
//

#pragma once

#include <iostream>
#include "./chessman.h"

class bishop : public chessman {

public:

    bishop(color color);
    ~bishop();

    color get_color() const;
    std::string get_figure() const;
    std::string get_name();
    bool is_essential() const;
    bool possible_move(pos origin, pos target, check_board **cb, int size) const;
    bool get_is_valid();
    void set_is_valid(bool is_valid);
    void calc_all_possible_moves(pos origin, check_board **cb, int size);
    void set_first_move_done(bool moved);

private:
    color m_color;
    std::string m_figure;
    std::string m_name{"bishop"};
    bool m_essential{false};
    bool m_is_valid{false};
    bool m_first_move_done{false};
};



