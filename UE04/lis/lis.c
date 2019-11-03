#include "./subsequence.h"

int main() {

  /* --------- Testcase 1 --------- */
  int seq1[] = {9,5,2,8,7,3,1,6,4};
  int n1 = sizeof(seq1) / sizeof(int);
  Testing(seq1,n1);

  /* --------- Testcase 2 --------- */
  int seq2[] = {1,2,4,5,-1,0,3,7,8,11};
  int n2 = sizeof(seq2) / sizeof(int);
  Testing(seq2,n2);

  /* --------- Testcase 3 --------- */
  int seq3[] = {124,23,75,11,0,463,1,7426};
  int n3 = sizeof(seq3) / sizeof(int);
  Testing(seq3,n3);

  /* --------- Testcase 4 --------- */
  int seq4[] = {256,14,18,21,2,3,4,0,71};
  int n4 = sizeof(seq4) / sizeof(int);
  Testing(seq4,n4);

  return EXIT_SUCCESS;
}

