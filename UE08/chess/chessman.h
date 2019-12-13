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
    virtual bool is_essential() const = 0;
    virtual bool possible_move(pos origin, pos target, check_board **cb, int size) const = 0;
    virtual bool get_is_valid() = 0;
    virtual void set_is_valid(bool is_valid) = 0;
    virtual std::string get_name() = 0;
    virtual void calc_all_possible_moves(pos origin, check_board **cb, int size) = 0;
    virtual void set_first_move_done(bool moved) = 0;
private:

};



