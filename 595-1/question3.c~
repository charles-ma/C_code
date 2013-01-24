#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

//sort an array of integers
void sort(int* a, int size){
  if(size == 0 || size == 1) return;
  mergeSort(a, 0, size - 1);
} 

//mergeSort, recursive, called by sort function
void mergeSort(int* a, int start, int end){
  if(start == end) return;
  int middle = (start + end) / 2;
  mergeSort(a, start, middle);
  mergeSort(a, middle + 1, end);
  merge(a, start, middle, end);
}

//merge two sorted arrays, called by mergerSort
void merge(int* a, int start, int middle, int end){
  int length1 = middle - start + 1;
  int length2 = end - middle;
  int tmp1[length1];
  int tmp2[length2];
  int i = 0, k = 0;
  for(; i < length1; i++) tmp1[i] = a[start + i];
  for(; k < length2; k++) tmp2[k] = a[middle + 1 + k];
  int j = start;
  i = 0;
  k = 0;
  for(; j <= end; j++){
    if(i == length1) {
      a[j] = tmp2[k];
      k++;
    }else if(k == length2) {
      a[j] = tmp1[i];
      i++;
    }else if(tmp1[i] < tmp2[k]){
      a[j] = tmp1[i];
      i++;
    }else{
      a[j] = tmp2[k];
      k++;
    }
  }
}
