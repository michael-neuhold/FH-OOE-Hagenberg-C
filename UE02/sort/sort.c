#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#define MAX 10

// print error msg
void printErr(char msg[]) {
  printf("<< Error (%s) >>\n", msg);
  return;
}

// Separator
void line() {
  for(int i = 0; i < 50; i++)
    printf("-");
  printf("\n");
  return;
}

// simply print elements of array separated by spaces
void printArr(int a[], int n) {
  for(int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  return;
}

// merge two subarrays
void merge(int a[], int from, int mid, int to){
  int tmp[MAX];
  int k = 0;

  int ai = from;  // start pos. first subarray
  int aj = mid+1; // start pos. second subarray

  while(ai <= mid && aj <= to) {
    if(a[ai] <= a[aj]){
      tmp[k++] = a[ai++];
    } else {
      tmp[k++] = a[aj++];
    }
  }

  // copy rest of first subarray
  while(ai <= mid){
    tmp[k++] = a[ai++];
  }

  // copy rest of second subarray
  while(aj <= to){
    tmp[k++] = a[aj++];
  }
  
  // copy tmp into original array
  int i,j;
  for(i=from,j=0;i<=to;i++,j++)
    a[i]=tmp[j];

  return;
}

// mergesort
void merge_sort_rec(int a[], int from, int to) {
  if (from < to) {
    int mid = (from + to) / 2;
    merge_sort_rec(a,from,mid);
    merge_sort_rec(a,mid+1,to);
    merge(a,from,mid,to);
  } 
  return;
}

// call recursive mergesort
void merge_sort (int a[], int n) {
  merge_sort_rec(a,0,n-1);
  return;
}

int main(int argc, char *argv[]) {

  int n;
  int a [MAX] = {0};
  
  if(argc > 1) {
    // to set n to the actual number of values in a
    if(argc-1 <= 10){
      n = argc-1;
    } else {
      n = 10;
    }

    // code to read a maximum of MAX values from argv to a and
    for(int i = 0; i < n; i++){
      a[i] = atoi(argv[i+1]);
    }
    
    // code to display the unsorted array a
    line();
    printf("original:\n");
    printArr(a,n);

    // call sorting algorithmus
    merge_sort(a, n);

    // code to display the sorted array a
    line();
    printf("sorted:\n");
    printArr(a,n);

    line();
  } else {
    printErr("there is nothing to sort!");
  }
  
  return EXIT_SUCCESS;
}
