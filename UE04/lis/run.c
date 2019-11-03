#include "./run.h"

/* --------- longest increasing run --------- */
int longest_increasing_run (int const s [], int const n) {
  int count = 1;
  int prev_count = 0;

  for(int i = 1; i < n; i++) {
    if(s[i-1] < s[i]) count++;    
    else {
      if(count > prev_count) prev_count = count;
      count = 1;
    }
  }
  return prev_count;
}