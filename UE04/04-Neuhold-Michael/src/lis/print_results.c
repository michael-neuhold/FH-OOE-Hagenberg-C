#include "./print_results.h" 

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

  // print index
  printf("n: \t");
  for(int i = 0; i < n; i++) printf("%d ", i);
  print_line();
  
  // print original sequence
  printf("s[i]: \t");
  print_table_row(s, n);

  // print subsequnece length
  printf("l[i]: \t");
  print_table_row(l, n);

  // print index of predecessor
  printf("p[i]: \t");
  print_table_row(p, n);
}

/* --------- Test Function --------- */
void Testing(int seq[], int n) {
  // longest increasing run
  print_header("<<< longest increasing run >>>");
  printf("max. run: %d\n", longest_increasing_run(seq,n));
  // longest increasing subsequence
  print_header("<<< longest increasing subsequence >>>");
  printf("max. sub-sequence length: %d\n\n", longest_increasing_subsequence(seq,n));
}