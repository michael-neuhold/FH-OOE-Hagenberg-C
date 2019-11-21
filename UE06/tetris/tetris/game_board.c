#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include "game_board.h"
#include <stdio.h>

#define MAX_BLOCK_COUNT ((GB_ROWS)*(GB_COLS))

static int block_count = 0;
static block blocks[MAX_BLOCK_COUNT];

bool gb_is_valid_position(const position pos) {

  if(!(pos.x >= 0 && pos.x < GB_COLS && pos.y >= 0 && pos.y < GB_ROWS)) {
      printf("-----\n");
      printf("--> is not a valid position...\n");
      printf("pos x: %d, pos y: %d", pos.x, pos.y);
      printf("\n-----\n");
    return false;
  } else {
      printf("XXXXXX\n");
  }
  // check collision with other tetriminos
  for(int i = 0; i < block_count;i++) {
    position block_pos = pos;
    if(pos.x == block_pos.x && pos.y == block_pos.y) {
      return false;
    }
  }
  return true;
}

void gb_add_block(const block block) {
  assert(gb_is_valid_position(block.pos));
  assert(block_count+1 < MAX_BLOCK_COUNT);
  blocks[block_count++] = block;
}

void gb_render() {
  for(int i = 0; i < block_count; i++) {
    render_block(blocks[i]);
  } 
}