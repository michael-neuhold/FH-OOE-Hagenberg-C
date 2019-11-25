#include <assert.h>
#include <GLFW/glfw3.h>

#include "types.h"
#include "./gameboard.h"

/*---------------------------------------------------------------------*/

void render_quad(const position * pos, const color * color) {
	assert(pos);
	assert(color);
	static_assert(sizeof(*color) == 4, "detected unexpected size for colors");
	glColor3ubv((unsigned char *)color);
	glBegin(GL_QUADS); {
		glVertex2f(pos->x + 0.025,     pos->y+ 0.025);
		glVertex2f(pos->x + 0.025,     pos->y + 0.975);
		glVertex2f(pos->x + + 0.975, pos->y + + 0.975);
		glVertex2f(pos->x + + 0.975, pos->y + 0.025);
	} glEnd();
}

/*---------------------------------------------------------------------*/

void init_tetromino() {

    /* J */
    tetromino tetro1 = {
            color_blue,
            .positions[0] = { 2 , 2 },
            .positions[1] = { 1 , 1 },
            .positions[2] = { 2 , 1 },
            .positions[3] = { 2 , 3 }
    };

    /* O */
    tetromino tetro2 = {
            color_yellow,
            .positions[0] = { 2 , 2 },
            .positions[1] = { 1 , 1 },
            .positions[2] = { 1 , 2 },
            .positions[3] = { 2 , 1 }
    };

    /* S */
    tetromino tetro3 = {
            color_green,
            .positions[0] = { 1 , 0 },
            .positions[1] = { 0 , 0 },
            .positions[2] = { 1 , 1 },
            .positions[3] = { 2 , 1 }
    };

    /* Z */
    tetromino tetro4 = {
            color_red,
            .positions[0] = { 1 , 0 },
            .positions[1] = { 0 , 1 },
            .positions[2] = { 1 , 1 },
            .positions[3] = { 2 , 0 }
    };

    /* I */
    tetromino tetro5 = {
            color_cyan,
            .positions[0] = { 2 , 1 },
            .positions[1] = { 1 , 1 },
            .positions[2] = { 3 , 1 },
            .positions[3] = { 4 , 1 }
    };

    /* T */
    tetromino tetro6 = {
            color_magenta,
            .positions[0] = { 2 , 1 },
            .positions[1] = { 1 , 1 },
            .positions[2] = { 3 , 1 },
            .positions[3] = { 2 , 2 }
    };

    /* L */
    tetromino tetro7 = {
            color_orange,
            .positions[0] = { 5 , 11 },
            .positions[1] = { 5 , 10 },
            .positions[2] = { 5 , 12 },
            .positions[3] = { 6 , 10 }
    };

    tetromino_blocks[0] = tetro1;
    tetromino_blocks[1] = tetro2;
    tetromino_blocks[2] = tetro3;
    tetromino_blocks[3] = tetro4;
    tetromino_blocks[4] = tetro5;
    tetromino_blocks[5] = tetro6;
    tetromino_blocks[6] = tetro7;
}

/*---------------------------------------------------------------------*/

void render_tetromino(tetromino *curr_tetro) {
    for(int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        render_quad(&(curr_tetro -> positions[i]), &(curr_tetro -> color));
    }
}