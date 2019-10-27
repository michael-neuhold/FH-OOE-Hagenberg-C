#include <stdio.h>
#include <stdlib.h>

#include "./pipelib.h"

int main(int argc, char *argv[]){

  int lengths[] = {4 , 2 , 8 };
  int counts[] =  {5 , 1 , 1 };
  int n = sizeof(lengths)/sizeof(int);
  
  int sol[MAX] = { 0 };
  int sum = 0;
  
  if(argc == 2) {
    
    printf("possibleIter: %d\n", possibleIter(atoi(argv[1]), lengths, counts, n));
    printf("possibleRec: %d\n", possibleRec(atoi(argv[1]), lengths, counts, n));
    printf("possibleBack: %d\n", possibleBack(atoi(argv[1]), lengths, counts, n));
  } else {
    printf("wrong number of arguments\n");
  }

  return EXIT_SUCCESS;
}