/* Neuhold Michael - Polygon */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// separator
void Line(void) {
  for(int i = 0; i <50; i++) printf("-");
  printf("\n");
  return;
}

// error message handling
void PrintErr(char msg[]) {
  printf("<< ERROR (%s) >>\n", msg);
  return;
}

// no parameters --> print info
void PrintInfo(char name[]) {
  Line();
  printf("How to use %s\n", name);
  printf("please add at least 3 coordinates x & y to the parameter list\n");
  printf("1. example: %s 1 1 -1 1 0 -1 \n", name);
  printf("2. example: %s x y  x y x  y ...\n", name);
  Line();
  return;
}

// print coordinates formated
void PrintCoo(int x, int y) {
  printf("[ x=%+d | y=%+d ]\n", x, y);
}

int main(int argc, char *argv[]) {
  int x_co, y_co, x_co_plus1, y_co_plus1; 
  double u = 0;

  Line();
  if(argc >= 7) {
    if((argc-1)%2==0) {
      for(int i = 3; i < argc; i=i+2) {
        x_co = atoi(argv[i-2]);
        y_co = atoi(argv[i-1]);
        x_co_plus1 = atoi(argv[i]);
        y_co_plus1 = atoi(argv[i+1]);
        PrintCoo(x_co, y_co);
        // calculate u interativ
        u += sqrt((pow((x_co_plus1 - x_co), 2) + pow(y_co_plus1 - y_co, 2)));
      }
      // print last coordinate
      PrintCoo(atoi(argv[argc-2]), atoi(argv[argc-1]));
      // close polygon
      u += sqrt((pow((atoi(argv[argc-2]) - atoi(argv[argc-4])), 2) + pow(atoi(argv[argc-3]) - atoi(argv[argc-1]), 2)));
      Line();
      printf("U: %f\n", u);
    } else {
      PrintErr("odd number of coordinates");
    }
  } else if (argc == 1) {
    PrintInfo(argv[0]); 
  } else {
    PrintErr("too few arguments");
  }
  Line();
  return 0;
}
