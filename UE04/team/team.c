#include "teamlib.h"

int main() {

  double test[] = { 10 , 12 , 14 , 16 , 18 , 20 , 22 , 24 };
  combinations(test, 8, 0);

  printstd();

  printf("avg: %f\n", avg(test,0,3));

  return EXIT_SUCCESS;
}


