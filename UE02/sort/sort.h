#ifndef sort_h
#define sort_h

// prototypes
void line(void);
void printArr(int a[], int n);
void printErr(char msg[]);
void merge(int a[], int from, int mid, int to);
void merge_sort_rec(int a[], int from, int to);
void merge_sort (int a[], int n);

#endif
