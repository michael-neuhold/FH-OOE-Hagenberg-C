//
// Created by Michael Neuhold on 05.12.19.
//

#pragma once

#include <iostream>
#include "types.h"


class chessman {

public:
    virtual color get_color() const = 0;
    virtual std::string get_figure() const = 0;
    virtual bool is_essential() const = 0;
    virtual bool possible_move(pos origin, pos target) const = 0;
    virtual pos get_position() = 0;
    virtual void set_position(pos position) = 0;
    virtual bool get_is_valid() = 0;
    virtual void set_is_valid(bool is_valid) = 0;
    virtual std::string get_name() = 0;
private:

};



