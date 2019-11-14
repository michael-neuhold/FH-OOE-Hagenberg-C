#ifndef TIMER_H
#define TIMER_H


typedef void (*timer_func)(void);

extern void timer_init(double interval, timer_func on_tick);
extern void timer_test();
extern void timer_reset();

#endif
