#ifndef CURRENT_BLOCK_H
#define CURRENT_BLOCK_H

#include "types.h"

extern bool cb_try_move(int dx, int dy);
extern void cb_render(void);
extern block cb_init_block(void);
extern block cb_get_block(void);

#endif