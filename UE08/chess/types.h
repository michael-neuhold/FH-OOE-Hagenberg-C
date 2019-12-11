//
// Created by Michael Neuhold on 05.12.19.
//

#pragma once

#include <iostream>
#include <sstream>
#define ALPHABET_LENGTH 26
#define SMALL_A 97

struct pos {

    // constructor for user input
    pos(int pos_x, int pos_y, char pos_yc) {
        x = pos_x - 1;
        y = (pos_y - 1) * ALPHABET_LENGTH + (int(pos_yc) - SMALL_A);
    }

    // constructor for internal calculations
    pos(int pos_x, int pos_y) {
        x = pos_x;
        y = pos_y;
    }

    pos(std::string coordinates) {
        std::istringstream iss(coordinates);
        char yc;
        char sep;
        //-- parse coordinates from string
        iss >> x;
        iss >> sep;
        iss >> sep;
        iss >> y;
        iss >> sep;
        iss >> yc;
        iss >> sep;
        //--s
        x--;
        y = (y - 1) * ALPHABET_LENGTH + (int(yc) - SMALL_A);
    }

    // default constructor
    pos() {
        x = -1;
        y = -1;
    }

    int x;
    int y;
};

enum class color { black , white };

struct check_board {
    bool is_set{false};
    std::string character_name;
    color color;
    bool moveable{false};
    bool killable{false};
};