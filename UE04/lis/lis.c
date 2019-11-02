#include "./lislib.h"


int main() {

  int seq[] = {9,5,2,8,7,3,1,6,4};
  int n = sizeof(seq) / sizeof(int);

  // longest increasing run
  print_header("longest increasing run");
  printf("max. run: %d\n", longest_increasing_run(seq,n));

  // longest increasing subsequence
  print_header("longest increasing subsequence");
  printf("max. sub-sequence length: %d\n", longest_increasing_subsequence(seq,n));

  return EXIT_SUCCESS;
}

