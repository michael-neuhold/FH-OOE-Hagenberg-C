#include "game_engine.h"
#include "current_block.h"
#include "game_board.h"
#include "./types.h"
#include <stdio.h>

//static bool game_over = false;

bool ge_handle_move(int dx, int dy) {
  if(!cb_try_move(dx,dy)) {
    if(dy == -1) {
      block current = cb_get_block();
      gb_add_block(current);
      //cb_render(); // added for debugging
      current = cb_init_block();

      printf("check new block after init new block pos x: %d, pos y: %d\n", current.pos.x, current.pos.y);
      if(!gb_is_valid_position(current.pos)) {
        //game_over = true;
        return false;
      }
      printf("after return false;\n");
    }
  }
  return true;
}

/*bool ge_is_game_over() {
  return game_over;
}*/