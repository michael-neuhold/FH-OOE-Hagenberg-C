#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 81
#define SUDOKU_SIZE 9
#define BIG_LINE_SIZE 27
#define SUB_SUDOKU_SIZE 3
#define TO_MILLISEC 1000
#define EMPTY 0

void print_line();
void print_big_line();
void print_err(char msg[]);
void print_sudoku(int squares[]);
bool check_line(int squares[], int i, int number);
bool check_col(int squares[], int i, int number);
bool check_square(int squares[], int i, int number);
bool check_elements(int squares[], int i, int number);
int find_empty_element(int squares[]);
bool sudoku_solve_rec(int squares[]);
void sudoku_solve(int squares[]);
