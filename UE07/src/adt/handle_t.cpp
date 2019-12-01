//
// Created by Michael Neuhold on 01.12.19.
//

#include "handle_t.h"

handle_t::handle_t(int index) {
    this -> identifier = index;
}

int handle_t::getIdentifier() const {
    return identifier;
}
