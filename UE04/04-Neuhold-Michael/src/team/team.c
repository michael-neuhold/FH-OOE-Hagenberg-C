#include "teamlib.h"

int main() {

  /* --------- testcases --------- */
  double laeufer1[] = { 10.3 , 12.5 , 13.7 , 9.9 , 10.1 , 11.0 , 12.4 , 10.3 , 9.7 , 10.7 , 11.2 , 20.9 , 20.6 };
  int n1 = sizeof(laeufer1) / sizeof(laeufer1[0]);
  double laeufer2[] = { 10 , 12 , 14 , 16 , 18 , 20 , 22 , 30 };
  int n2 = sizeof(laeufer2) / sizeof(laeufer2[0]);
  double laeufer3[] = { 18.3 , 14.2 , 9.1 , 8.0 , 9.13 , 13.3 , 22.4 , 29.1, 30.9 };
  int n3 = sizeof(laeufer3) / sizeof(laeufer3[0]);
  double laeufer4[] = { };
  int n4 = sizeof(laeufer4) / sizeof(laeufer4[0]);

  /* --------- find perfect solution --------- */
  combinations(laeufer1, n1, 0);
  printstd();

  combinations(laeufer2, n2, 0);
  printstd();

  combinations(laeufer3, n3, 0);
  printstd();

  combinations(laeufer4, n4, 0);
  printstd();

  return EXIT_SUCCESS;
}
