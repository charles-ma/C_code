#include <stdio.h>

int main(){
  int x = 1, y = 1;
  int *p, *q;
  p = &x;
  q = &y;
  int k = (p == q);
  printf("%d\n", k);
}
