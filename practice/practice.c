#include <stdio.h>

add(int a, int b){//no return value declared does not mean there is no return value by default
  return a + b;
}

int main(){
  int x = 1, y = 1;
  int *p, *q;
  p = &x;
  q = &y;
  int k = (p == q);
  printf("%d\n", k);
  printf("%d\n", add(1,3));
}
