#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <stdbool.h>
#include "types.h"

#define GB_ROWS 22
#define GB_COLS 11
#define NUMBER_OF_BLOCKS 4

typedef struct {
    bool is_set;
    color block_color;
} fixed;

/*----------------------------------------------------*/

fixed fixed_blocks[GB_COLS][GB_ROWS];
bool gb_is_valid_position(const position* pos);
void gb_update(tetromino tetro);
void gb_render(void);
void init_fixed_blocks();

/*----------------------------------------------------*/

#endif
