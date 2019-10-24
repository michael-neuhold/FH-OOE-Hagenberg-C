#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 81


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

bool check_row(int squares[], int i, int number) {
  //printf("row: \n");
  int col = (i + 1) % 9;
  /* printf("col nr: %d\n", col);
  printf("startindex of row: %d \n", i - col + 1); */
  int start = i - col + 1;
  for(int j = start; j < start + 9; j++) {
    // printf(",%d", squares[j]);
    if(number == squares[j])
      return false;
  }
  return true;
}

bool check_col(int squares[], int i, int number) {
  // printf("col: \n");
  int row_nr = i / 9;
  int start_at = i - 9 * row_nr;
  /* printf("row_nr: %d\n",row_nr);
  printf("start at: %d\n", start_at); */
  int end_at = start_at + 9 * 8;
  for(int j = start_at; j <= end_at; j = j + 9) {
    //printf(",%d", squares[j]);
    if(squares[j] == number){
      return false;
    }
  }
  return true;
}

bool check_square(int squares[], int i, int number) {
  printf("checking 3x3 \n");
  int row_nr = i / 9;
  int col_nr = i % 9;

  int offset = col_nr % 3;
  //int big_col = col_nr / 3; 
  //printf("offset col: %d\n", offset);
  //printf("big_col_nr: %d\n", big_col);

  int first_index_col = i - offset;
  //printf("first index col: %d\n", first_index_col);

  //int big_line = col_nr / 3; 
  int offset_row = row_nr % 3;
  //printf("offset row: %d\n", offset_row);
  //printf("big line nr: %d\n", big_line);

  int first_index_square =  first_index_col - 9 * offset_row;
  //printf("first index of small square: %d\n", first_index_square);

  bool correct = true;
  int limit = first_index_square + 9 * 2 + 6;

  //printf("square: \n");
  int j = first_index_square;
  while(correct && (j <= limit)) {
    printf(",%d", squares[j]); 
    if(squares[j] == number){
      correct = false;
    }
    if((j + 1) % 3 == 0){
      j = j + 7;
    } else {
      j++;
    }
  }
  return correct;
}

bool check_elements(int squares[], int i, int number) {
  return /*check_row(squares,i,number) && */check_col(squares,i,number) && check_square(squares,i,number) /*&& squares[i] == 0*/;
}

int find_empty_element(int squares[]) {
  for(int i = 0; i <= 80; i++) {
    if(squares[i] == 0) {
      printf("return ( i ): %d\n",i);
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
    printf("i: %d, squares[] = %d, number: %d\n", i, squares[i], number);
    if(check_elements(squares,i,number) /*true*/) {
      squares[i] = number;
   
    if(sudoku_solve(squares)){
      return true;
    } else {
      squares[i] = 0;
    } }
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


  printSudoku(squares);
  printf("--> solve sudoku: %d\n",sudoku_solve(squares)); 
  printSudoku(squares);


  printf(" --> %d ",check_square(squares, 0,10));
  printf(" --> %d ",check_square(squares, 3,10));
  printf(" --> %d ",check_square(squares, 6,10));
  printf(" --> %d ",check_square(squares, 27,10));
  printf(" --> %d ",check_square(squares, 30,10));
  printf(" --> %d ",check_square(squares, 33,10));
  printf(" --> %d ",check_square(squares, 54,10));
  printf(" --> %d ",check_square(squares, 57,10));
  printf(" --> %d ",check_square(squares, 60,10));

  return EXIT_SUCCESS;
}









