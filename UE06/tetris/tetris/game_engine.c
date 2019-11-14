#include "game_engine.h"
#include "current_block.h"
#include "game_board.h"
#include "./types.h"

static bool game_over = false;

bool ge_handle_move(int dx, int dy) {
  if(!cb_try_move(dx,dy)) {
    if(dy == -1) {
      block current = cb_get_block();
      gb_add_block(current);
      
      current = cb_init_block();
      if(!gb_is_valid_position(current.pos)) {
        game_over = true;
        return false;
      }
    }
  }
  return true;
}

bool ge_is_game_over() {
  return game_over;
}