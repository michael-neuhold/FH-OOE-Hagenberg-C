//
// Created by Michael Neuhold on 06.12.19.
//

#include "player.h"

player::player(std::string name, color color) : m_name{name} , m_color{color} {
}

std::string player::get_name() const {
    return m_name;
}

color player::get_color() const {
    return m_color;
}