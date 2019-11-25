#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "gameboard.h"
#include "timer.h"

#define WIDTH  400
#define HEIGHT WIDTH * (GB_ROWS / GB_COLS)
#define SPEED_STEP 0.02

#define BLOCK_SELECT rand() % 7

// select specific tetromino for testing
// #define BLOCK_SELECT 0

static bool game_over;
tetromino current;

/*---------------------------------------------------------------------*/

static bool try_move(int dx, int dy) {
    bool valid = true;
    for(int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        position pos = current.positions[i];
        pos.x += dx;
        pos.y += dy;
        if (!gb_is_valid_position(&pos)) valid = false;
    }
    if(valid) {
        for(int j = 0; j < NUMBER_OF_BLOCKS; j++) {
            current.positions[j].x += dx;
            current.positions[j].y += dy;
        }
    }
	return valid;
}

/*---------------------------------------------------------------------*/

static int current_max_y() {
    int max = 0;
    for(int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        if(current.positions[i].y > max) max = current.positions[i].y;
    }
    return max;
}

/*---------------------------------------------------------------------*/

static int current_max_x() {
    int max = 0;
    for(int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        if(current.positions[i].x > max) max = current.positions[i].x;
    }
    return max;
}

/*---------------------------------------------------------------------*/

static void set_current_to_top() {
    int offset_y = GB_ROWS - current_max_y();
    int offset_x = (GB_COLS / 2) - current_max_x();
    for(int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        current.positions[i].y += offset_y - 1;
        current.positions[i].x += offset_x + 1;
    }
}

/*---------------------------------------------------------------------*/

static int line_is_full() {
    for (int i = 0; i < GB_ROWS; i++) {
        bool full = true;
        for(int j = 0; j < GB_COLS; j++) {
            if(!fixed_blocks[j][i].is_set) {
                full = false;
            }
        }
        if(full) {
            printf("line is full\n");
            return i;
        }
    }
    return -1;
}

/*---------------------------------------------------------------------*/

static void clear_line(int line_nr) {
    for (int i = line_nr + 1; i < GB_ROWS; i++) {
        for(int j = 0; j < GB_COLS; j++) {
            fixed_blocks[j][i-1].is_set = fixed_blocks[j][i].is_set;
            fixed_blocks[j][i-1].block_color = fixed_blocks[j][i].block_color;
        }
    }
    for(int i = 0; i < GB_COLS; i++) {
        fixed_blocks[i][GB_ROWS - 1].is_set = false;
    }
}

/*---------------------------------------------------------------------*/

static void rotate_tetro() {

    tetromino tmp_tetromino = current;
    bool valid = true;

    // move to origin
    for(int i = 0; i < NUMBER_OF_BLOCKS; i++) {

        // move to origin
        tmp_tetromino.positions[i].x -= current.positions[0].x;
        tmp_tetromino.positions[i].y -= current.positions[0].y;

        // rotation matrix
        int new_x = 0 * tmp_tetromino.positions[i].x + 1 *  tmp_tetromino.positions[i].y;
        int new_y = -1 * tmp_tetromino.positions[i].x + 0 * tmp_tetromino.positions[i].y;
        tmp_tetromino.positions[i].x = new_x;
        tmp_tetromino.positions[i].y = new_y;

        // move to correct position
        tmp_tetromino.positions[i].x += current.positions[0].x;
        tmp_tetromino.positions[i].y += current.positions[0].y;
        if (!gb_is_valid_position(&tmp_tetromino.positions[i])) valid = false;
    }

    if(valid) current = tmp_tetromino;
}

/*---------------------------------------------------------------------*/

static void on_key(GLFWwindow* window, int key, int scancode, int action, int modifiers) {
	bool rotate = false;
	if (game_over) return;
	int dx = 0, dy = 0;
	switch (key) {
		case GLFW_KEY_DOWN:     dy = -1;    break;
		case GLFW_KEY_UP:
		    if (action == GLFW_PRESS || action == GLFW_REPEAT) { rotate_tetro(); rotate = true; }
		    break;
		case GLFW_KEY_LEFT:     dx = -1;    break;
		case GLFW_KEY_RIGHT:    dx = +1;    break;
		default: return; //ignore other keys
	}

	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && !rotate) {
         if (!try_move(dx, dy)) { //why couldnt we move
            if (dy == -1) { //tried to move down => hit bottom!
                gb_update(current);

                /********************************************/

                // check if line is full
                int line_nr = line_is_full();
                while(line_nr != -1) {
                    clear_line(line_nr);
                    line_nr = line_is_full();
                }
                // update current with new random block
                current = tetromino_blocks[BLOCK_SELECT];
                set_current_to_top();
                // increment speed
                timer_interval -= SPEED_STEP;
                printf("current speed: %f\n", timer_interval);

                /********************************************/

                if (!gb_is_valid_position(current.positions)) game_over = true;
                timer_reset();
            }
        }
	}
}

/*---------------------------------------------------------------------*/

// simulate keypress
static void on_timer(void) {
    on_key(NULL, GLFW_KEY_DOWN, 0, GLFW_PRESS, 0);
}

int main() {
	if(!glfwInit()) {
		fprintf(stderr, "could not initialize GLFW\n");
		return EXIT_FAILURE;
	}

    /********************************************/
	// init different tetromino blocks
    init_tetromino();
	// init fixed blocks
	init_fixed_blocks();
    /********************************************/

	GLFWwindow * const window = glfwCreateWindow(WIDTH, HEIGHT, "Tetris", NULL, NULL);
	if(!window) {
		glfwTerminate();
		fprintf(stderr, "could not open window\n");
		return EXIT_FAILURE;
	}

	int width, height;
	glfwGetWindowSize(window, &width, &height);
	glfwSetWindowAspectRatio(window, width, height);//enforce correct aspect ratio
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, &on_key);
	timer_init(&on_timer);

	/********************************************/
	// set first random tetromino
    current = tetromino_blocks[BLOCK_SELECT];
    // set current to top
    set_current_to_top();
    /********************************************/

	while(!glfwWindowShouldClose(window)) {
		timer_test();

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);//clear frame buffer
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, width, 0, height);//orthogonal projection - origin is in lower-left corner
		glScalef((float)width / (float)GB_COLS, (float)height / (float)GB_ROWS, 1);//scale logical pixel to screen pixels

        /********************************************/
        // render current tetromino
        render_tetromino(&current);
		// render fixed blocks at the bottom
		gb_render();
        /********************************************/

		const GLenum error = glGetError();
		if(error != GL_NO_ERROR) fprintf(stderr, "ERROR: %s\n", gluErrorString(error));
		glfwSwapBuffers(window);//push image to display
		glfwWaitEventsTimeout(timer_interval); // sleep
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return EXIT_SUCCESS;
}
