#ifndef TIMER_H
#define TIMER_H

typedef void(*timer_callback)(void);

extern double timer_interval;

void timer_init(timer_callback func);
void timer_test(void);
void timer_reset(void);

#endif