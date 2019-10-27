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

// prints separator betweene BIG_LINE_SIZE
void print_line() {
  for(int i = 0; i < 21; i++)
    printf("-");
  printf("\n");
}

// prints separator between testcases
void print_big_line() {
  for(int i = 0; i < 50; i++)
    printf("=");
  printf("\n");
}

// prints error
void print_err(char msg[]) {
  printf("<< ERROR (%s) >>\n", msg);
}

// prints sudoku to console
void print_sudoku(int squares[]){
  print_line();
  for(int i = 0; i < MAX; i++){
    if(squares[i] == EMPTY){
      printf("- ");
    } else {
      printf("%d ",squares[i]);
    }
    if((i+1) % SUB_SUDOKU_SIZE == 0 && (i+1) % SUDOKU_SIZE != 0)
      printf("| ");
    if((i+1) % SUDOKU_SIZE == 0) 
      printf("\n");
    if((i+1) % BIG_LINE_SIZE == 0)
      print_line();
  }
  return;
}

// returns true if number is valid in line/row
// else false
bool check_line(int squares[], int i, int number) {
  int start = i - (i % SUDOKU_SIZE);
  int end = start + SUDOKU_SIZE - 1;
  for(int j = start; j <= end; j++ ) {
    if(squares[j] == number) {
      return false;
    }
  }
  return true;
}

// returns true if number is valid in col
// else false
bool check_col(int squares[], int i, int number) {
  int start = i - SUDOKU_SIZE * (i / SUDOKU_SIZE);
  int end = start + SUDOKU_SIZE * SUDOKU_SIZE - 1;
  for(int j = start; j <= end; j += SUDOKU_SIZE) {
    if(squares[j] == number) {
      return false;
    }
  }
  return true;
}

// returns true if number is valid in sub_square
// else false
bool check_square(int squares[], int i, int number) {
  int line_nr = i / SUDOKU_SIZE;
  int col_nr = i % SUDOKU_SIZE;
  int line_offset = line_nr % SUB_SUDOKU_SIZE;
  int col_offset = col_nr % SUB_SUDOKU_SIZE;

  int sub_square_top = i - SUDOKU_SIZE * line_offset;
  int sub_square_start = sub_square_top - col_offset;
  int sub_square_end = sub_square_start + 2 * SUDOKU_SIZE + 2;

  int j = sub_square_start;

  while(j <= sub_square_end){
    if(squares[j] == number){
      return false;
    } else if((j + 1) % SUB_SUDOKU_SIZE == 0) {
      j += SUDOKU_SIZE - 2;
    } else {
      j++;
    }
  }
  return true;
}

// returns if number is valid at index i
bool check_elements(int squares[], int i, int number) {
  return  check_square(squares,i,number) && 
          check_line(squares,i,number) && 
          check_col(squares,i,number);
}

// returns index of next empty square 
// if there is no empty square return -1
int find_empty_element(int squares[]) {
  for(int i = 0; i <= MAX-1; i++) {
    if(squares[i] == EMPTY) {
      return i;
    }
  }
  return -1;
}

// recursive function with backtracking
bool sudoku_solve_rec(int squares[]) {

  int i = find_empty_element(squares);

  if(i == -1){
    return true;
  }

  for(int number = 1; number <= SUDOKU_SIZE; number++) {
    if(check_elements(squares,i,number)) {
      squares[i] = number;
      if(sudoku_solve_rec(squares)){
        return true;
      } else {
        squares[i] = EMPTY;
      } 
    }
  }
  return false;
}

// solve sudoku calls recursive function
void sudoku_solve(int squares[]) {
  clock_t start, end = 0;
  print_sudoku(squares);
  start = clock();
  if(sudoku_solve_rec(squares)) {
    end = clock();
    print_sudoku(squares);
  } else {
    print_err("could not be solved");
  }
  printf("time: %f ms\n", ((double)((end - start)) / CLOCKS_PER_SEC) * TO_MILLISEC);
}

int main() {

  // testcases 
  int squares1[MAX] = { 
                        5,0,9 , 0,0,0 , 0,0,7 ,
                        0,8,0 , 0,1,0 , 5,2,0 ,
                        0,0,3 , 0,8,4 , 0,0,1 ,

                        0,9,0 , 7,0,0 , 0,0,2 ,
                        4,0,0 , 0,5,0 , 3,9,0 , 
                        8,0,2 , 1,0,0 , 0,0,4 ,

                        0,0,0 , 3,0,2 , 0,0,5 ,
                        0,4,0 , 0,0,0 , 7,0,0 ,
                        1,0,7 , 0,9,0 , 0,8,0    
                      };

  int squares2[MAX] = { 
                        0,1,0 , 0,0,8 , 4,9,6 ,
                        0,4,0 , 0,6,1 , 0,0,0 ,
                        0,9,0 , 0,0,0 , 5,7,0 ,

                        6,0,7 , 0,0,0 , 0,1,0 ,
                        0,0,0 , 4,1,7 , 0,0,3 , 
                        0,0,0 , 6,0,0 , 0,0,2 ,

                        1,0,9 , 8,0,0 , 0,4,0 ,
                        0,0,4 , 0,9,3 , 6,0,0 ,
                        0,0,0 , 7,4,5 , 0,2,0    
                      };

  int squares3[MAX] = { 
                        3,0,0 , 0,0,0 , 0,0,1 ,
                        0,7,6 , 0,0,0 , 5,3,0 ,
                        0,1,9 , 0,4,0 , 7,2,0 ,

                        0,0,0 , 8,0,6 , 0,0,0 ,
                        0,0,1 , 0,7,0 , 9,0,0 , 
                        0,0,0 , 5,0,4 , 0,0,0 ,

                        0,3,5 , 0,6,0 , 2,8,0 ,
                        0,8,7 , 0,0,0 , 6,5,0 ,
                        6,0,0 , 0,0,0 , 0,0,7    
                      };

  int squares4[MAX] = { 
                        0,0,1,	2,0,7,	0,0,0,
                        0,6,2,	0,0,0,	0,0,0,
                        0,0,0,	0,0,0,	9,4,0,
                          
                        0,0,0,	9,8,0,	0,0,3,
                        5,0,0,	0,0,0,	0,0,0,
                        7,0,0,	0,3,0,	0,2,1,
                            
                        0,0,0,	1,0,2,	0,0,0,
                        0,7,0,	8,0,0,	4,1,0,
                        3,0,4,	0,0,0,	0,8,0 
                      };

  // tests
  printf("1. Sudoku\n");
  sudoku_solve(squares1);
  print_big_line();
  printf("2. Sudoku\n");
  sudoku_solve(squares2);
  print_big_line();
  printf("3. Sudoku\n");
  sudoku_solve(squares3);
  print_big_line();
  printf("4. Sudoku\n");
  sudoku_solve(squares4);
  print_big_line();

  return EXIT_SUCCESS;
}
