#ifndef TYPES_H
#define TYPES_H

#include <assert.h>
#include <stdbool.h>

#define GB_ROWS 22
#define GB_COLS 11

// max size of sub squars
#define MAX_SUBSQUARE_COUNT 4

// number of tetrominos
#define NUM_OF_TETROMINO

#define UNUSED(var) ((void)var)

typedef enum {
	color_black,
	color_red     = 0x0000FFU,
	color_green   = 0x00FF00U,
	color_blue    = 0xFF0000U,
	color_yellow  = color_red   | color_green,
	color_magenta = color_red   | color_blue,
	color_cyan    = color_green | color_blue,
	color_white   = color_red   | color_green | color_blue,
} color;

typedef struct {
	int x, y;
} position;

typedef struct tetromino {
    color color;
    float center;
    position positions[MAX_SUBSQUARE_COUNT];
} tetromino;

//tetromino tetrominos[NUM_OF_TETROMINO];

extern void render_quad(const position pos, const color color);

typedef struct {
  position pos;
  color color;
} block;  

extern void render_block(const block block);
extern void render_tetrominos(const tetromino tetromino);
extern void init_tetrominos();

#endif
