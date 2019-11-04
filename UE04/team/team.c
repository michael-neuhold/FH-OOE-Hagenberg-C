#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#define TEAM_SIZE 4
#define MAX_RUNNERS 40
#define MAX_TEAMS MAX_RUNNERS / TEAM_SIZE
#define USED -1

// returns avg with start and end index
double avg(double elem[],int start,int n) {
  double sum = 0;
  for(int i = start; i < start+n; i++){
    sum += elem[i];
  }
  return sum / n;
}

// calculate
double std_variation(double teams[], int n) {
  double mean = avg(teams,0,n);

  double tmp = 0;

  for(int i = 0; i < (n / TEAM_SIZE); i++ ) {
    tmp += pow((avg(teams, i * TEAM_SIZE, TEAM_SIZE) - mean),2) ;
  }
  tmp = tmp / (n / TEAM_SIZE);
  return sqrt(tmp);
}

/* =============================================== */

int team_count = 0;
int teams[MAX_RUNNERS] = { 0 };
double minStd = 999;
bool is_used[MAX_RUNNERS] = { 0 };

void combinations(const double runners[], const int n, int start) {
  if((team_count % TEAM_SIZE == 0) && (n - team_count) < TEAM_SIZE) {
    for (int i = 0; i < 8; i++)
    {
      printf("%d ",teams[i]);
    }
    printf("\n");
    double team_time[MAX_RUNNERS];
    for (int i = 0; i < team_count; i++)
    {
      team_time[i] = runners[teams[i]];
    }
    if(minStd > std_variation(team_time,team_count)) {
      printf("new");
      minStd = std_variation(team_time,team_count);
    }
    return;
  } else if((team_count % TEAM_SIZE == 0) ) {
    start = 0;
  }

  for (int i = start; i < n; i++) {
    if(!is_used[i]) {
      teams[team_count++] = i;
      is_used[i] = true;
      combinations(runners, n, i + 1);
      team_count--;
      is_used[i] = false;
    }
  }
  return;
}

/* =============================================== */

int main() {

  double test[] = { 10 , 12 , 14 , 16 , 18 , 20 , 22 , 24 };
  combinations(test, 8, 0);

  printf("minStd: %f\n", minStd); 

  printf("avg: %f\n", avg(test,0,3));

  return EXIT_SUCCESS;
}
