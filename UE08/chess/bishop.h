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
    bool possible_move(pos origin, pos target) const;
    pos get_position();
    void set_position(pos position);
    bool get_is_valid();
    void set_is_valid(bool is_valid);
    std::string get_name();

private:
    color m_color;
    std::string m_figure;
    bool m_essential{true};
    pos m_position;
    bool m_is_valid{false};
    std::string m_name{"bishop"};
};



