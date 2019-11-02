#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#define MAX 100

/* --------- print result functions --------- */
void print_line();
void print_header(char msg[]);
void print_table_row(int a[], int n);
void print_result(int s[], int l[], int p[], int n);

/* --------- longest increasing run --------- */
int longest_increasing_run (int const s [], int const n);

/* --------- longest increasing subsequence --------- */
int longest_increasing_subsequence (int const s [], int const n);