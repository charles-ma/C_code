#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
  char* s = (char*)malloc(sizeof(char) * 4); 
  strcpy(s, "adc") ;
  int i = 0;
  while(s[i] != '\0') {
    i++;
  }
  int j = 0;
  i = i - 1;
  while(j < i) {
    char c = s[i];
    *(s + i) = s[j];
    *(s + j) = c;
    i--;
    j++;
  }
  printf("%s", s);
}
