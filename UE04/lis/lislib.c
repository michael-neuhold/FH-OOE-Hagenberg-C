#include "./lislib.h"

/* --------- print result functions --------- */

// separator
void print_line() {
  printf("\n");
  for(int i = 0; i < 50; i++){
    printf("-");
  }
  printf("\n");
  return;
}

// print header
void print_header(char msg[]) {
  print_line();
  printf("%s", msg);
  print_line();
  return;
}

// iterate over array elements
void print_table_row(int a[], int n) {
  for(int i = 0; i < n; i++) {
    if(a[i] == INT_MIN) printf("  ");
    else printf("%d ", a[i]);
  }
  print_line();
}

// print result table
void print_result(int s[], int l[], int p[], int n) {
  //
  printf("n: \t");
  for(int i = 0; i < n; i++) printf("%d ", i);
  print_line();
  
  //
  printf("s[i]: \t");
  print_table_row(s, n);

  //
  printf("l[i]: \t");
  print_table_row(l, n);

  //
  printf("p[i]: \t");
  print_table_row(p, n);
}

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
    //printf("s[i-1] = %d, s[i] = %d,count: %d\n", s[i-1], s[i],count);
  }
  return prev_count;
}

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