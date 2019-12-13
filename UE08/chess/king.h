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
    bool is_essential() const;
    bool possible_move(pos origin, pos target, check_board **cb, int size) const;
    bool get_is_valid();
    void set_is_valid(bool is_valid);
    virtual std::string get_name();
    void calc_all_possible_moves(pos origin, check_board **cb, int size);
    void set_first_move_done(bool moved);

private:
    color m_color;
    std::string m_figure;
    bool m_essential{true};
    bool m_is_valid{false};
    std::string m_name{"king"};
    bool m_first_move_done{false};
};



