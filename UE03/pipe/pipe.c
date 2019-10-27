#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pipelib.h"

int main(int argc, char *argv[]){

  int lengths[] = {2 , 3 , 5 };
  int counts[] =  {2 , 1 , 3 };
  int n = sizeof(lengths)/sizeof(int);
  
  int sol[MAX] = { 0 };
  int sum = 0;

  if(argc == 2){
    printf("%d entered lengths\n",n);
    printf("search length: %d\n",atoi(argv[1]));
    //printf("possible: %d\n", possibleRec(atoi(argv[1]), lengths, counts, n));
    printf("possibleIter: %d\n", possibleIter(atoi(argv[1]), lengths, counts, n));
    printf("possibleRec: %d\n", possibleRec(atoi(argv[1]), lengths, counts, n));
    printf("possibleBack: %d\n", possibleBack(atoi(argv[1]), lengths, counts, n));
   //test3(atoi(argv[1]), lengths, counts, n-1, sum);
  } else {
    printf("wrong number of arguments\n");
  }

  return EXIT_SUCCESS;
}