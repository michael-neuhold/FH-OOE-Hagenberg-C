#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30


bool possibleRec (int const x, int const lengths [], int counts [], int n, int sum);

bool valid(int x, int lengths[], int sol[], int n){
  int sum = 0;
  for(int i = 0; i < n; i++ ){
    sum += lengths[i] * sol[i];
  }
  return sum == x;
}

bool possibleRec (int const x, int const lengths [], int counts [], int n, int sum) {
  
  //if(i < n) return false; 
  //printf("<<< sum: %d\n", sum);
  if(sum == x) {
    printf("found solution");
    return true; 
  }
  //if(n < 0) return false;
  int i = counts[n];
  while(i >= 0 && n >= 0) {
    sum = sum + lengths[n] * i;
    printf("n: %d, i: %d, length: %d, count: %d, sum: %d\n",n, i, lengths[n],counts[n], sum);
    if (sum < x) {  
      possibleRec(x,lengths,counts,n-1,sum);
    } else {
      possibleRec(x,lengths,counts,n-1,0);
    }
    i--;
  }
  return false;
}

bool rec(int const x, int const lengths [], int counts [], int n, int sum) {
  
  if(n < 0) return false;
  printf("n: %d\n", n);
  printf("sum: %d\n", sum);
  for(int i = counts[n]; i >= 0; i--) {
    sum += lengths[n] * i;
    if(sum == x) {
      printf("found");
      return true;
    } else {
      rec(x,lengths,counts,n-1,sum);
    }
  }
}

void test(int const x, int const lengths [], int counts [], int n, int sum) {
  if(n >= 0){
  
    for(int i = counts[n]; i >= 0; i--) {
      sum += lengths[n] * i;
      if(sum == x) {
        printf("found\n");
      }
      printf("i: %d\t, lengths: %d, n: %d, sum: %d\n",i, lengths[n],n, sum);
      if (sum < x){
        test(x,lengths,counts,n-1,sum);
      } else {
        sum -= lengths[n] * i;
      }
      
  }
  }
  return;
}

bool test2(int const x, int const lengths [], int counts [], int n, int sum) {
  if(n >= 0){
    
    for(int i = counts[n]; i >= 0; i--) {
      sum += lengths[n] * i;
      if(sum == x) {
        printf("found\n");
        return true;
      }
      printf("i: %d\t, lengths: %d, n: %d, sum: %d\n",i, lengths[n],n, sum);
      if (sum < x){
        return test2(x,lengths,counts,n-1,sum);
      } else {
        sum = 0;
      }
    }
  } 
  return false;
}

/* bool possibleRec (int const x, int const lengths [], int counts [], int const n, int sum, int i) {
  if(sum == x){
    return true;
  }
  printf("sum..: %d", sum);
  sum += lengths[i];
  if(sum > counts[i]*lengths[i]){
    sum = 0;
    i++;
    if(i < n){
      return possibleRec(x,lengths,counts,n,sum,i);
    } else {
      return false;
    }
  } else {
    return possibleRec(x,lengths,counts,n,sum,i);
  }
} */

int main(int argc, char *argv[]){

  int lengths[] = {2 , 3 , 5 };
  int counts[] =  {2 , 1 , 3 };
  int n = sizeof(lengths)/sizeof(int);
  
  int sol[MAX] = { 0 };
  int sum = 0;

  if(argc == 2){
    printf("%d entered lengths\n",n);
    printf("search length: %d\n",atoi(argv[1]));
    //printf("possible: %d\n", test2(atoi(argv[1]), lengths, counts, n-1, sum));
   test(atoi(argv[1]), lengths, counts, n-1, sum);
  } else {
    printf("wrong number of arguments\n");
  }

  return EXIT_SUCCESS;
}
