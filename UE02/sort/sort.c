#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Separator
void Line() {
  for(int i = 0; i < 50; i++)
    printf("-");
  printf("\n");
  return;
}

// simply print elements of array separated by spaces
void PrintArr(int a[], int n) {
  for(int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  return;
}

// merge two subarrays
void merge(int a[], int from, int mid, int to){
  int tmp[10];
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
  
  // copy tmp int0 original array
  int i,j;
  for(i=from,j=0;i<=to;i++,j++)
    a[i]=tmp[j];
}

void merge_sort_rec(int a[], int from, int to) {
  if (from < to) {
    int mid = (from + to) / 2;
    merge_sort_rec(a,from,mid);
    merge_sort_rec(a,mid+1,to);
    merge(a,from,mid,to);
  } 
  return;
}

void merge_sort (int a[], int n) {
  merge_sort_rec(a,0,n-1);
  return;
}

int main(int argc, char *argv[]) {

  int n = 0;
  int a [MAX] = {0};
  
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
  Line();
  printf("original:\n");
  PrintArr(a,n);

  merge_sort(a, n);

  // code to display the sorted array a
  Line();
  printf("sorted:\n");
  PrintArr(a,n);

  Line();
  return EXIT_SUCCESS;
}
