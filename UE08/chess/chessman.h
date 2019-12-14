//
// Created by Michael Neuhold on 05.12.19.
//

#pragma once

#include <iostream>
#include "types.h"


class chessman {

public:
    virtual ~chessman() = default;
    virtual color get_color() const = 0;
    virtual std::string get_figure() const = 0;
    virtual std::string get_name() const = 0;
    virtual bool is_essential() const = 0;
    virtual void calc_all_possible_moves(pos origin, check_board **cb, const int size) = 0;
    virtual void set_first_move_done(bool moved) = 0;
private:

};



