//
// Created by Michael Neuhold on 29.11.19.
//

#include "vertex_t.h"

vertex_t::vertex_t(std::string payload) {
    this -> payload = payload;
}

std::string vertex_t::get_payload() {
    return this -> payload;
}