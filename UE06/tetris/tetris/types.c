#include <GLFW/glfw3.h>
#include "types.h"

void render_quad(const position pos, const color color) {
	static_assert(sizeof(color) == 4, "detected unexpected size for colors");
	glColor3ubv((unsigned char *)&color);
	glBegin(GL_QUADS); {
		glVertex2i(pos.x,     pos.y);
		glVertex2i(pos.x,     pos.y + 1);
		glVertex2i(pos.x + 1, pos.y + 1);
		glVertex2i(pos.x + 1, pos.y);
	} glEnd();
}


/*-------------------------------------------------------------*/

void render_block(const block block) {
  render_quad(block.pos, block.color);
}

/*-------------------------------------------------------------*/
/*
void init_tetrominos() {
    init_tetro_I();
    init_tetro_L();
    init_tetro_S();
    init_tetro_Z();
    init_tetro_O();

    init_tetro_I();
    init_tetro_I();
}
*/
/*-------------------------------------------------------------*/

/* render tetromino (4 separate blocks) */
void render_tetrominos(const tetromino tetromino) {
    for(int i = 0; i < MAX_SUBSQUARE_COUNT; i++) {
        render_quad(tetromino.positions[i], tetromino.color);
    }
}