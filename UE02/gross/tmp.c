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

void Line() {
  for(int i = 0; i < 50; i++)
    printf("-");
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

// divide and conquer (Quicksort)
void partition(int a[], int left, int right, int ith) {
  int i = left;
  int j = right;
  int pivot = a[(left+right)/2];
  do {
    while(a[i] < pivot) {
      i++;
    }
    while(pivot < a[j]) {
      j--;
    }
    if(i <= j) {
      if(a[i] != a[j] ) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
      i++;
      j--;
    }
  } while(i<=j);
  
  if(left < j && (10-ith) < (i+j)/2) {
    partition(a,left, j, ith);
  }
  if(i < right && (10-ith) > (i+j)/2) {
    partition(a,i,right, ith);
  }

  if(10-ith == (j+i)/2){
    printf(">>>>>>>>>> (%d) ith-largest Element: %d\n",ith, a[(j+i)/2]);
    return;
  }
  //printf("%d \n",a[(left+right)/2]);
  return;
}

void ith_largest_2(int a[],int n,int i) {
  partition(a,0,n-1,i);
  PrintArr(a,MAX);
  return;
}


/* ================================================= */


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
  printf("ith-largest [i=3] => %d\n",ith_largest_1(a,MAX,2));

  // 3.
  Line();
  //InitArr(a,MAX);
  //int b[] = {3,5,1,7,8,3,7,9,2,9};
  InitArr(a,MAX);
  PrintArr(a,MAX);
  //ith_largest_2(a,MAX,5);
  //quick_sort(a,0,MAX,3);
  //PrintArr(a,MAX);
  ith_largest_2(a,MAX,8);
  //printf("ith-largest [i=4] => %d\n", ith_largest_2(a,MAX,2));

  return 0;
}