#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#define TEAM_SIZE 4
#define MAX_RUNNERS 40
#define MAX_TEAMS MAX_RUNNERS / TEAM_SIZE
#define USED -1s

/* --------- help functions --------- */
double avg(double elem[],int start,int n);
double std_variation(double teams[], int n);

/* --------- find all combinations and update min. standard variation --------- */
void combinations(const double runners[], const int n, int start);

/* --------- print final standard variation --------- */
void printstd(void);