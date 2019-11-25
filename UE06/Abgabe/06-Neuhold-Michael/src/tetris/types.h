#ifndef TYPES_H
#define TYPES_H

#define NUMBER_OF_TETROMINOS 7

typedef enum {
	color_black,
	color_red     = 0x0000FFU,
	color_green   = 0x00FF00U,
	color_blue    = 0xFF0000U,
	color_orange  = 0x0095FFU,
	color_yellow  = color_red   | color_green,
	color_magenta = color_red   | color_blue,
	color_cyan    = color_green | color_blue,
	color_white   = color_red   | color_green | color_blue,
} color;

typedef struct {
	int x, y;
} position;

typedef struct {
    color color;
    position positions[4];
} tetromino;

tetromino tetromino_blocks[NUMBER_OF_TETROMINOS];

/*----------------------------------------------------*/

void init_tetromino();
void render_tetromino(tetromino *curr_tetro);
void render_quad(const position * pos, const color * color);

/*----------------------------------------------------*/

#endif
