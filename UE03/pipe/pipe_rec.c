#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30


bool possibleRec (int const x, int const lengths [], int const counts [], int n);

bool possibleRec (int const x, int const lengths [], int const counts [], int n){
  if(x == 0) return true;
  else if (n > 0) {
    bool is_possible = false;
    for(int i = 0; i <= counts[n-1]; i++) {
      is_possible = is_possible || possibleRec(x - (lengths[n-1]*i),lengths,counts, n-1);
    }
    return is_possible;
  } else return false;
}

bool possibleBack (int const x, int const lengths [], int const counts [], int n){
  if(x == 0) return true;
  else if (n > 0) {
    bool is_possible = false;
    for(int i = 0; i <= counts[n-1]; i++) {
      if(x >= 0){
        is_possible = is_possible || possibleRec(x - (lengths[n-1]*i),lengths,counts, n-1);
      }
    }
    return is_possible;
  } else return false;
}

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
    printf("possible: %d\n", possibleBack(atoi(argv[1]), lengths, counts, n));
   //test3(atoi(argv[1]), lengths, counts, n-1, sum);
  } else {
    printf("wrong number of arguments\n");
  }

  return EXIT_SUCCESS;
}
