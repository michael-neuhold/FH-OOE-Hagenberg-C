#include <assert.h>
#include <stdbool.h>
#include "gameboard.h"
#include <stdio.h>

/*---------------------------------------------------------------------*/

void init_fixed_blocks() {
    for (int i = 0; i < GB_ROWS; i++) {
        for(int j = 0; j < GB_COLS; j++) {
            fixed_blocks[j][i].is_set = false;
        }
    }
}

/*---------------------------------------------------------------------*/

bool gb_is_valid_position(const position* pos) {
	assert(pos);
	if (pos-> x < 0 || pos-> y < 0 || pos-> x >= GB_COLS || pos -> y >= GB_ROWS) return false;
    for (int i = 0; i < GB_ROWS; i++) {
        for(int j = 0; j < GB_COLS; j++) {
            if(fixed_blocks[j][i].is_set && pos->x == j && pos->y == i) {
                return false;
            }
        }
    }
	return true;
}

/*---------------------------------------------------------------------*/

void gb_update(tetromino tetro) {
	for(int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        fixed_blocks[tetro.positions[i].x][tetro.positions[i].y].is_set = true;
	    fixed_blocks[tetro.positions[i].x][tetro.positions[i].y].block_color = tetro.color;
	}
}

/*---------------------------------------------------------------------*/

void gb_render(void) {
	for (int i = 0; i < GB_ROWS; i++) {
	    for(int j = 0; j < GB_COLS; j++) {
	        position pos;
	        pos.x = j;
	        pos.y = i;
	        if(fixed_blocks[j][i].is_set) {
	            render_quad(&pos, &fixed_blocks[j][i].block_color);
	        }
	    }
	}
}

/*---------------------------------------------------------------------*/
