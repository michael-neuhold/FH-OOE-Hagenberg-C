#include <assert.h>
#include <GLFW/glfw3.h>
#include "timer.h"

static timer_func callback;
static double interval = 0.2;

void timer_init(double interval, timer_func on_tick) {
  assert(on_tick);
  interval = interval;
  callback = on_tick;
  timer_reset();
}

void timer_test() {
  assert(callback);

  if(glfwGetTime() >= interval) {
    callback();
    timer_reset();
  }
}

void timer_reset() {
  glfwSetTime(0);
}