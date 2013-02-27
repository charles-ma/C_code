#include <stdio.h>

int add(int, int);

int main(int argc, char** argv){
  int x = 1, y = 1;
  int *p, *q;
  p = &x;
  q = &y;
  int k = (p == q);
  printf("%d\n", k);
  printf("%d\n", add(1,3));
  printf("%s\n", *argv);
  char z[] = {'1', '2', '3'};
  char* ptr = z;
  printf("%c\n", *(ptr + 1));
}

add(int a, int b){//no return value declared does not mean there is no return value by default
  return a + b;
}
