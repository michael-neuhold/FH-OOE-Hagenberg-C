/* Neuhold Michael - NOVA-Calculator */

#include <stdio.h>
#include <stdlib.h>

// separator
void Line(void) {
  for(int i = 0; i < 50; i++) printf("-");
  printf("\n");
  return;
}

// error message handling
void PrintErr(char msg[]) {
  printf("<< ERROR (%s) >>\n",msg);
}

// print formated result to console
void PrintRes(char fuel[], double nova) {
  printf("FUEL: %s\n", fuel);
  printf("NOVA: %4.2f%%\n", nova);
}

// returns calculated NOVA in %
// factor depends on the fuel
double NOVA(double consumption, int factor){
  return (consumption - factor) * 2;
}

// 1.param: fuel
// 2.param: average consumption
int main(int argc, char *argv[]) {
  Line();
  if(argc == 3) {
    if(atoi(argv[1]) == 1){
      PrintRes("Diesel", NOVA(atof(argv[2]),2));
    } else if(atoi(argv[1]) == 2) {
      PrintRes("Benzin", NOVA(atof(argv[2]),3));
    } else {
      PrintErr("please check your input parameters");
    }  
  } else {
    PrintErr("please enter parameters: fuel consumption");
  }
  Line();
  return 0;
}
