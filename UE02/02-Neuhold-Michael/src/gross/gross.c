#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

void printArr(int a[], int n) {
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

void InitArr(int a[], int n) {
  for(int i = 0; i < n; i++){
    a[i] = rand() % 1000;
  }
}

// print error msg
void printErr(char msg[]) {
  printf("<< Error (%s) >>\n", msg);
  return;
}

/* ================================================= */
// 2.1.

int second_largest(int a[], int n) {
  int f = INT_MIN;  // first 
  int s = INT_MIN;  // second

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
// 2.2. 

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

int ith_largest_1(int a[], int n, int i) {
  merge_sort(a,n);
  return a[i-1];
}

/* ================================================= */
// 2.3. 

// swap values in array
void swap(int *a, int *b) {
  int h = *a;
  *a = *b;
  *b = h;
}

// return selected pivo element
int pivot_elem(int a[], int left, int right) {
  
  // pivot candidate
  int pc[3] = { 
    a[left], 
    a[(left+right)/2], 
    a[right] 
  };

  // sort candidates
  if (pc[0] > pc[1]) {
    swap(&pc[0], &pc[1]);
  }
  if (pc[1] > pc[2]) {
    swap(&pc[1], &pc[2]);
  } 
  if (pc[0] > pc[1]) {
    swap(&pc[0], &pc[1]);
  }

  return pc[1];
}

// brings elements to the right side of pivot
int split(int a[], int left, int right, int pivot) {
  // split
  do {
    while (a[left] < pivot) {
      left++;
    }
    while (a[right] > pivot) {
      right--;
    } 
    swap(&a[left], &a[right]);
  } while (left < right);
  
  // return position of pivot
  if (a[left] == pivot) return left;
  return right;
}


// search largest element in array (linear)
int get_largest(int a[], int left, int right) {
  int max_value = a[left];
  left++;

  for (int i = left; i <= right; i++) {
    if (max_value < a[i]) {
      max_value = a[i];
    }
  }
  return max_value;  
}

// serach ith-largest element
int search_ith_largest(int a[], int left, int right, int i) {
  if(i == 1) {
    return get_largest(a, left, right);
  }
  
  // get value of pivot element (candidates: left, middle, right)
  int pivot = pivot_elem(a, left, right);

  // split elements of array --> < / > than pivot
  int pivot_pos  = split(a, left, right, pivot);

  int right_size = right - pivot_pos + 1;

  if (right_size >= i) {
    return search_ith_largest(a, pivot_pos, right, i);
  } else {
    return search_ith_largest(a, left, pivot_pos-1, i-right_size);
  }
}

int ith_largest_2(int a[], int n, int i) {
  return search_ith_largest(a, 0, n-1, i);
}

/* ================================================= */

int main (int argc, char *argv[]) {
  
  int a[MAX];
  
  if(argc == 2) {

    int ith = atoi(argv[1]);

    // 1.
    Line();
    InitArr(a,MAX); // init with random numbers
    printf("second_largest => %d\n", second_largest(a,MAX));
    printArr(a,MAX);

    // 2.
    Line();
    InitArr(a,MAX); // init with random numbers
    printf("ith-largest [i=%d] => %d\n",ith, ith_largest_1(a,MAX,ith));
    printArr(a,MAX);

    // 3.
    Line();
    InitArr(a,MAX); // init with random numbers
    printf("ith-largest [i=%d] => %d\n",ith, ith_largest_2(a,MAX,ith));
    printArr(a,MAX);
  } else {
    printErr("wrong number of parameters");
  }

  return 0;
}
