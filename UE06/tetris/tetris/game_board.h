#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <stdbool.h>
#include "types.h"

extern bool gb_is_valid_position(const position pos);
extern void gb_add_block(const block block);
extern void gb_render();

#endif
