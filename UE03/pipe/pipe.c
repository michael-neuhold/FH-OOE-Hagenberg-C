#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./pipelib.h"

#define TO_MILLISEC 1000

int main(int argc, char *argv[]){

  int lengths[] = {4 , 2 , 8 };
  int counts[] =  {5 , 1 , 1 };
  int n = sizeof(lengths)/sizeof(int);
  
  int sol[MAX] = { 0 };
  int sum = 0;
  
  if(argc == 2) {
    clock_t start, end = 0;
    start = clock();
    printf("possibleIter: %d\n", possibleIter(atoi(argv[1]), lengths, counts, n));
    printf("time: %f ms\n", ((double)((clock() - start)) / CLOCKS_PER_SEC) * TO_MILLISEC);
    start = clock();
    printf("possibleRec: %d\n", possibleRec(atoi(argv[1]), lengths, counts, n));
    printf("time: %f ms\n", ((double)((clock() - start)) / CLOCKS_PER_SEC) * TO_MILLISEC);
    start = clock();
    printf("possibleBack: %d\n", possibleBack(atoi(argv[1]), lengths, counts, n));
    printf("time: %f ms\n", ((double)((clock() - start)) / CLOCKS_PER_SEC) * TO_MILLISEC);
  } else {
    printf("wrong number of arguments\n");
  }

  return EXIT_SUCCESS;
}