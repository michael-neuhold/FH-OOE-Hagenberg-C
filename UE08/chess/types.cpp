//
// Created by Michael Neuhold on 08.12.19.
//

#include "./types.h"

user_pos convert_to_user_pos(pos position) {
    user_pos user_position;
    user_position.x = position.x;
    user_position.y = position.y / ALPHABET_LENGTH;
    user_position.yc = char(SMALL_A + (position.y % ALPHABET_LENGTH));
    return user_position;
}

pos convert_to_internal_pos(user_pos user_position) {
    pos position;
    position.x = user_position.x - 1;
    position.y = (user_position.y - 1) * ALPHABET_LENGTH + (int(user_position.yc) - SMALL_A);
    return position;
}