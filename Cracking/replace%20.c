#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* s = (char*)malloc(sizeof(char) * 10);
  strcpy(s, "asd g  rg");
  int spaces = 0;
  int i = 0;
  while(s[i] != '\0') {
    if(s[i] == ' ') spaces++;
    i++;
  }
  s = (char*)realloc(s, sizeof(char) * (10 + spaces * 2));
  i = 9;
  int j = 9 + spaces * 2;
  for(; i >= 0; i--) {
    if(s[i] == ' ') {
      s[j] = '0';
      s[j - 1] = '2';
      s[j - 2] = '%';
      j = j - 3;
    }
    else {
      s[j] = s[i];
      j--;
    }
  }
  printf("%s\n", s);
}
