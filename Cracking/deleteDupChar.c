#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* s = (char*)malloc(sizeof(char) * 9);
  s = strcpy(s, "assdfghf");
  int i = 0, j = 1;
  while(s[j] != '\0') {
    int k = 0;
    for(; k <= i; k++) {
      if(s[k] == s[j]) {
	j++;
	break;
      }
    }
    if(k == i + 1) {
      i++;
      s[i] = s[j];
      j++;
    }
  }
  s[i + 1] = '\0';
  printf("%s\n", s);
}
