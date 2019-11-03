#include "./subsequence.h"
#include "./print_results.h"

/* --------- longest increasing subsequence --------- */
int longest_increasing_subsequence (int const s [], int const n) {

  int max, pred;

  int l[MAX];
  int p[MAX];

  l[0] = 1;         // count subsequence length (first elemnt always 1)
  p[0] = INT_MIN;   // first element does not have a predecessor

  for(int i = 0; i < n; i++) {
    max = 0;
    pred = INT_MIN; // no predecessor as default

    for(int j = 0; j < i; j++) { // for each i --> iterate over the previos elements
      if((s[j] < s[i]) && (max < l[j])) {
        // new max and store location of predecessor
        max = l[j];
        pred = j;
      }
      l[i] = max + 1; // subsequence max value 
      p[i] = pred;
    }
  }

  // get the longest subsequence 
  max = INT_MIN;
  for(int i = 1; i < n; i++) {
    if(max < l[i])
      max = l[i];
  }

  print_result(s,l,p,n);
  
  return max;
}
