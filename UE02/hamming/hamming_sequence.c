#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hamming(int x) {
  while(x % 5 == 0)
    x = x / 5;
  while(x % 3 == 0)
    x = x / 3;
  while(x % 2 == 0)
    x = x / 2;
  return x == 1;
}

int main(int argc, char *argv[]) {

  if(argc == 2){
    double start = clock();
    for(int i = 1; i <= atoi(argv[1]); i++){
      if(hamming(i)) {
        printf("%d", i);
      }
    }  

    printf("\ntime: %f", (clock() - start) / CLOCKS_PER_SEC);

    printf("\n");
  } else {
    printf("ERROR\n");
  }
  

  return 0;
}
