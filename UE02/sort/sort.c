#include <stdio.h>
#include <stdlib.h>
#define MAX 100


void PrintArr(int a[], int n) {
  for(int i = 0; i < n; i++){
    printf("a[%d] = %d ", i, a[i]);
  }
  printf("\n");
  return;
}

void merge(int a[], int from, int mid, int to){
  int tmp[10];
  int k = 0;

  int ai = from;
  int aj = mid+1;

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
  
  // copy tmp int original array
  int i,j;
  for(i=from,j=0;i<=to;i++,j++)
    a[i]=tmp[j];
}

void merge_sort_rec(int a[], int from, int to) {
  int mid;
  if (from < to) {
    mid = (from + to) / 2;
    merge_sort_rec(a,from,mid);
    merge_sort_rec(a,mid+1,to);
    merge(a,from,mid,to);
  } else {
    return;
  }
}

void merge_sort (int a[], int n) {
  merge_sort_rec(a,0,n-1);
}

int main(int argc, char *argv[]) {

  int n = 0;
  int a [MAX] = {0};


  // code to read a maximum of MAX values from argv to a and
  // to set n to the actual number of values in a

  if(argc-1 <= 10){
    n = argc-1;
  } else {
    n = 10;
  }

  for(int i = 0; i < n; i++){
    a[i] = atoi(argv[i+1]);
  }
  
  // code to display the unsorted array a
  printf("original:\n");
  PrintArr(a,n);

  merge_sort(a, n);

  // code to display the sorted array a
  printf("sorted:\n");
  PrintArr(a,n);

  return EXIT_SUCCESS;
}
