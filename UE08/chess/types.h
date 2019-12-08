//
// Created by Michael Neuhold on 05.12.19.
//

#pragma once

#define ALPHABET_LENGTH 26
#define SMALL_A 97

struct pos {
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