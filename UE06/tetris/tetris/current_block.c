#include <stdlib.h>
#include "current_block.h"
#include "game_board.h"
#include <stdio.h>

static block current = { { GB_COLS / 2, GB_ROWS - 1 }, color_red };

static color random_color() {
  static color colors[] = { 
    color_red,    
    color_green,  
    color_blue,   
    color_yellow, 
    color_magenta,
    color_cyan,   
    color_white  
  };
  int n_colors = sizeof(colors) / sizeof(colors[0]);
  return colors[rand() % n_colors];
}

bool cb_try_move(int dx, int dy) {
  position pos = current.pos;
  pos.x += dx;
  pos.y += dy;
  // check if new position is a valid position
  if(!gb_is_valid_position(pos)) {
    return false;
  }
  // if valid update position
  current.pos = pos;
  return true;
}

void cb_render(void) {
  render_block(current);
}

block cb_init_block(void) {
  current.pos.x = GB_COLS / 2;
    current.pos.y = GB_ROWS - 1;
    current.color = random_color();
    printf("------>>>\n");
  printf("color of block: %d\n", current.color);
  printf("current xpos: %d, ypos: %d\n", current.pos.x, current.pos.y);
    printf("------>>>\n");
  return current;
}

block cb_get_block(void) {
  return current;
}