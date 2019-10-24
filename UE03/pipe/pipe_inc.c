#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30


bool possible (int const x, int const lengths [], int const counts [], int const n);

bool valid(int x, int lengths[], int sol[], int n){
  int sum = 0;
  for(int i = 0; i < n; i++ ){
    sum += lengths[i] * sol[i];
  }
  return sum == x;
}

bool inc(int sol[], int counts[], int n){
  bool run;
  int i = 0;

  do {
    sol[i]++;
    run = false;
    if(sol[i] > counts[i]) {
      sol[i] = 0;
      i++;
      if(i < n){
        run = true;
      } else {
        return false;
      }
    }
  } while(run);

  return true;
}

bool possible (int const x, int const lengths [], int const counts [], int const n){
  int sol[MAX] = { 0 };
  do {

    if(valid(x, lengths, sol,n)){
      return true;
    }

  } while(inc(sol, counts, n));
  return false;
}

int main(int argc, char *argv[]){

  int lengths[] = {2 , 3 , 5 };
  int counts[] =  {1 , 4 , 3 };
  int n = sizeof(lengths)/sizeof(int);

  if(argc == 2){
    printf("%d entered lengths\n",n);
    printf("search length: %d\n",atoi(argv[1]));
    printf("possible: %d\n", possible(atoi(argv[1]), lengths, counts, n));
  } else {
    printf("wrong number of arguments\n");
  }

  return EXIT_SUCCESS;
}
