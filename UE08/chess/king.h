//
// Created by Michael Neuhold on 05.12.19.
//

#pragma once

#include <iostream>
#include "chessman.h"

class king : public chessman {

public:

    king(color color);
    ~king();

    color get_color() const;
    std::string get_figure() const;
    std::string get_name() const;
    bool is_essential() const;
    void calc_all_possible_moves(pos origin, check_board **cb, const int size);
    void set_first_move_done(bool moved);

private:
    color m_color;
    std::string m_figure;
    std::string m_name{"king"};
    bool m_essential{true};
    bool m_first_move_done{false};
};



