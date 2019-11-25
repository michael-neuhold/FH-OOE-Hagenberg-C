#include <assert.h>
#include <GLFW/glfw3.h>
#include "timer.h"

double timer_interval = 1;

static
timer_callback callback;

void timer_init(timer_callback func) {
	assert(func);
	assert(!callback);
	callback = func;
	timer_reset();
}

void timer_test(void) {
	assert(callback);
	if (glfwGetTime() >= timer_interval) {
		callback();
		timer_reset();
	}
}

void timer_reset(void) {
	glfwSetTime(0);
}