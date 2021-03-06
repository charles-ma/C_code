#include <stdlib.h>
#include <stdio.h>

//create a stringArray containing 10 strings of size 15(14 characters) on the heap
void createStringArray(){
  char** strings = (char**) malloc(10 * sizeof(char*));
  int i = 0;
  for(; i < 10; i++){
    strings[i] = (char*) malloc(15 * sizeof(char));
    int j = 0;
    for(; j < 14; j++){
      strings[i][j] = 'a';
    }
    strings[i][j] = '\0';
  }
  printf("\ntest for generating a string array\n");
  i = 0;
  for(; i < 10; i++){
    printf("%s\n", strings[i]);
    free(strings[i]);
  }
  free(strings);
}
