#include "./sudokulib.h"

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