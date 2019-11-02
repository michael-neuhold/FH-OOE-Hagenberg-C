#ifndef pipelib_h
#define pipelib_h
#include <stdbool.h>

#define MAX 30

bool possibleIter (int const x, int const lengths [], int const counts [], int const n);
bool possibleRec (int const x, int const lengths [], int const counts [], int const n);
bool possibleBack (int const x, int const lengths [], int const counts [], int const n);
bool is_valid(int x, int const lengths[], int sol[], int n);
bool inc(int sol[], int const counts[], int n);

#endif