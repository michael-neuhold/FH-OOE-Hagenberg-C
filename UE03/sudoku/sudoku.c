#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 81
#define SUB_SQUARE_SIZE 9
#define BIG_LINE_SIZE 27
#define SUB_SQUARE_LINE_SIZE 3


void printLine() {
  for(int i = 0; i < 21; i++)
    printf("-");
  printf("\n");
}

void printSudoku(int squares[]){
  printLine();
  for(int i = 0; i < MAX; i++){
    printf("%d ",squares[i]);
    if((i+1) % 3 == 0 && (i+1) % 9 != 0)
      printf("| ");
    if((i+1) % 9 == 0) 
      printf("\n");
    if((i+1) % 27 == 0)
      printLine();
  }
  return;
}

bool check_line(int squares[], int i, int number) {
  int start = i - (i % 9);
  int end = start + 8;
  for(int j = start; j <= end; j++ ) {
    if(squares[j] == number) {
      return false;
    }
  }
  return true;
}

bool check_col(int squares[], int i, int number) {
  int start = i - 9 * (i / 9);
  int end = start + 9 * 8;
  for(int j = start; j <= end; j += 9) {
    if(squares[j] == number) {
      return false;
    }
  }
  return true;
}

bool check_square(int squares[], int i, int number) {
  int line_nr = i / 9;
  int col_nr = i % 9;
  int line_offset = line_nr % 3;
  int col_offset = col_nr % 3;

  int sub_square_top = i - 9 * line_offset;
  int sub_square_start = sub_square_top - col_offset;
  int sub_square_end = sub_square_start + 2 * 9 + 2;

  int j = sub_square_start;

  while(j <= sub_square_end){
    if(squares[j] == number){
      return false;
    } else if((j + 1) % 3 == 0) {
      j += 7;
    } else {
      j++;
    }
  }
  return true;
}

bool check_elements(int squares[], int i, int number) {
  return check_square(squares,i,number) && check_line(squares,i,number)  && check_col(squares,i,number);
}

int find_empty_element(int squares[]) {
  for(int i = 0; i <= 80; i++) {
    if(squares[i] == 0) {
      //printf("return ( i ): %d\n",i);
      return i;
    }
  }
  return -1;
}


bool sudoku_solve(int squares[]) {

  // find cell with squares[i] == 0
    // -> if there is no --> return true
  // for 1 to 9 
    // if there is no conflict than assign number from for loop
    // if recursion successfull return true
    // else remove digit and try another number
  // if all digits have been tried return false

  int i = find_empty_element(squares);
  if(i == -1){
    return true;
  }

  for(int number = 1; number <= 9; number++) {
    if(check_elements(squares,i,number)) {
      squares[i] = number;
      if(sudoku_solve(squares)){
        return true;
      } else {
        squares[i] = 0;
      } 
    }
  }
  return false;
}

int main() {

  int squares[MAX] = { 
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

  printSudoku(squares3);

  clock_t start = clock();
  printf("--> solve sudoku: %d\n",sudoku_solve(squares3)); 
  clock_t end = clock();
  
  printf("time: %f ms\n", ((double)((end - start)) / CLOCKS_PER_SEC) * 1000);

  printSudoku(squares3);

  return EXIT_SUCCESS;
}









