#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

void PrintArr(int a[], int n) {
  for(int i = 0; i < n; i++){
    printf("a[%d] = %d ", i, a[i]);
  }
  printf("\n");
  return;
}

/* ================================================= */
void merge(int a[], int from, int mid, int to){
  int tmp[10];
  int k = 0;

  int ai = from;
  int aj = mid+1;

  while(ai <= mid && aj <= to) {
    if(a[ai] >= a[aj]){
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
  return;
}

/* ================================================= */

int ith_largest_1(int a[], int n, int i) {
  merge_sort(a,MAX);
  PrintArr(a,MAX);
  return a[i-1];
}

/* ================================================= */

void InitArr(int a[], int n) {
  for(int i = 0; i < n; i++){
    a[i] = rand() % 1000;
  }
}

/* ================================================= */

int second_largest(int a[], int n) {
  int f = INT_MIN;  // first 
  int s = INT_MIN;  // second
  PrintArr(a,n);

  if(n >= 2) {
    for(int i = 0; i < n; i++){
      if(a[i] > f){
        s = f;
        f = a[i];
      } else if (a[i] > s){
        s = a[i];
      }
    }
  } else {
    printf("ERROR\n");
  }
  return s;
}

/* ================================================= */

int ith_largest_1(int a[],int n,int i) {
  
  return 1;
}

/* ================================================= */

void Line() {
  for(int i = 0; i < 50; i++)
    printf("-");
  printf("\n");
  return;
}
/* ================================================= */

int main (int argc, char *argv[]) {
  
  int a[MAX];
  
  // 1.
  Line();
  InitArr(a,MAX);
  printf("secons_largest => %d\n", second_largest(a,MAX));

  // 2.
  Line();
  InitArr(a,MAX);
  printf("ith-largest [i=3] => %d\n",ith_largest_1(a,MAX,3));

  // 3.
  Line();
  InitArr(a,MAX);
  printf("ith-largest [i=4] => %d\n", ith_largest_2(a,MAX,4));

  return 0;
}