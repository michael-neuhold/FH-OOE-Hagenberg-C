#include "./pipelib.h"

/*** recursive ***/
bool possibleRec (int const x, int const lengths [], int const counts [], int const n){
  if(x == 0) return true;
  else if (n > 0) {
    bool is_possible = false;
    for(int i = 0; i <= counts[n-1]; i++) {
      is_possible = is_possible || possibleRec(x - (lengths[n-1]*i),lengths,counts, n-1);
    }
    return is_possible;
  } else return false;
}

/*** backtracking ***/
bool possibleBack (int const x, int const lengths [], int const counts [], int const n){
  if(x == 0) return true;
  else if (n > 0) {
    bool is_possible = false;
    for(int i = 0; i <= counts[n-1]; i++) {
      if(x >= 0){
        is_possible = is_possible || possibleRec(x - (lengths[n-1]*i),lengths,counts, n-1);
      }
    }
    return is_possible;
  } else return false;
}

/*** iterativ ***/

bool is_valid(int x, int const lengths[], int sol[], int n) {
  int sum = 0;
  for(int i = 0; i < n; i++ ){
    sum += lengths[i] * sol[i];
  }
  return sum == x;
}

bool inc(int sol[], int const counts[], int n) {
  bool run;
  int i = 0;

  do {
    sol[i] += 1;
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

// returns true if it is possible and false if not
bool possibleIter(int const x, int const lengths [], int const counts [], int const n) {
  // sol = solutions --> array to safe "virtual indices of FOR loops"
  int sol[MAX] = { 0 };
  do {
    if(is_valid(x, lengths,sol,n)){
      return true;
    }
  } while(inc(sol, counts, n));
  return false;
}
