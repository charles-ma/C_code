#include <stdio.h>
#include <stdlib.h>

int *a;
int ind;
int length;

void initializeArray(int n){
  a = malloc(n * sizeof(int));
  length = n;
  ind = 0;
}

void add(int b){
  if(ind < length){
    a[ind] = b;
    ind++;
  }else if(ind == length){
    length *= 2;//use 2 as increasing factor
    //length++;//+1 to increase
    a = realloc(a, length * sizeof(int));
    a[ind] = b;
    ind++;
  }
}

void removeElement(){
  if(ind != 0){
    ind--;
    a[ind] = NULL;
  }
}

int get(int i){
  if(0 <= i && i < ind) return a[i];
  return NULL;
}

void destroyArray(){
  free(a);
}
