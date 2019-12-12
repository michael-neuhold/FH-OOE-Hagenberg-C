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
    bool is_essential() const;
    bool possible_move(pos origin, pos target, check_board **cb, int size) const;
    bool get_is_valid();
    void set_is_valid(bool is_valid);
    std::string get_name();
    void calc_all_possible_moves(pos origin, check_board **cb, int size);

private:
    color m_color;
    std::string m_figure;
    bool m_essential{false};
    bool m_is_valid{false};
    std::string m_name{"bishop"};
};



