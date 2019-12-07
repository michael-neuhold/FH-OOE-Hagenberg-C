//
// Created by Michael Neuhold on 06.12.19.
//

#pragma once

#include <iostream>
#include "./types.h"

class player {

public:
    player() = delete;
    player(std::string name, color color);
    std::string get_name() const;
    color get_color() const;
    ~player() = default;

private:
    std::string m_name;
    color m_color;
};



