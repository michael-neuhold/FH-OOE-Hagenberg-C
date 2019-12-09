//
// Created by Michael Neuhold on 05.12.19.
//

#pragma once

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

    // default constructor
    pos() {
        x = -1;
        y = -1;
    }

    int x;
    int y;
};

struct user_pos {
    int x;
    int y;
    char yc;
};

enum class color { black , white };

user_pos convert_to_user_pos(pos position);

pos convert_to_internal_pos(user_pos user_position);