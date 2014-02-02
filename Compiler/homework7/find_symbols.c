#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int offsV = 0;//global variable indicating the # of local variables
int offsP = 4;//global variable indicating the # of parameters

int parse_function_header(char *header, int lineNum)
{
  if (header == NULL) return 0;

  // these are the 10 strings that you will populate
  char s0[10];
  char s1[10];
  char s2[10];
  char s3[10];
  char s4[10];
  char s5[10];
  char s6[10];
  char s7[10];
  char s8[10];
  char s9[10];
  char *strings[] = {s0, s1, s2, s3, s4, s5, s6, s7, s8, s9};
  
  printf("Calling tokenize function with input \"%s\".\n", header);
  int numWords = tokenize(header, strings);

  // let's see what got tokenized
  //  printf("The tokens are: \n");
  //  int i = 0;
  //  for (i = 0; i < 10; i++) {
  //printf("%s\n", strings[i]);
  //  }

  // NOW LOOK AT EACH ELEMENT IN strings AND FIND THE PARAMETERS!
  int *e = malloc(sizeof(int));
  if(strcmp(strings[3], "") && strcmp(strings[3], "{")){
    if(get_offset(strings[3], e)){
      printf("The variable name %s in line %d has been used.", strings[3], lineNum);
      return 0;
      }
    add_node(strings[3], offsP++);
  }
  
  if(strcmp(strings[5], "")){
    if(get_offset(strings[5], e)){
      printf("The variable name %s in line %d has been used.", strings[5], lineNum);
      return 0;
      }
    add_node(strings[5], offsP++);
  }

  if(strcmp(strings[7], "")){
    if(get_offset(strings[7], e)){
      printf("The variable name %s in line %d has been used.", strings[7], lineNum);
      return 0;
      }
    add_node(strings[7], offsP++);
  }
  return 1;
}



int parse_line(char *line, int lineNum)
{
  if (line == NULL) return 0;
  // these are the 10 strings that you will populate
  char s0[10];
  char s1[10];
  char s2[10];
  char s3[10];
  char s4[10];
  char s5[10];
  char s6[10];
  char s7[10];
  char s8[10];
  char s9[10];
  char *strings[] = {s0, s1, s2, s3, s4, s5, s6, s7, s8, s9};
  
  printf("Calling tokenize function with input \"%s\".\n", line);
  int numWords = tokenize(line, strings);

  // let's see what got tokenized
  //  printf("The tokens are: \n");
  //  int i = 0;
  //  for (i = 0; i < 10; i++) {
  //printf("%s\n", strings[i]);
  //  }

  // NOW LOOK AT EACH ELEMENT IN strings AND FIND THE VARIABLE DECLARATIONS!
  int j = 0;
  int k = 0;
  int *m = malloc(sizeof(int));
  //  printf("The variables are:\n");
  if(strcmp(strings[0], "int") == 0){
    for(j = 1; j < 10; j++){
      char c = strings[j][0];
      if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
	if(strcmp(strings[j - 1], "=") && strcmp(strings[j - 1], "+")){
	  //printf("%d", get_offset(strings[j], m));
	  if(get_offset(strings[j], m)){
	    printf("The variable name %s in line %d has been used.\n", strings[j], lineNum);
	    return 0;
	  }
	  add_node(strings[j], offsV--);
	}
	else{
	  if(get_offset(strings[j], m) == 0){
	    printf("The variable %s used in line %d has not been initialized.\n", strings[j], lineNum);
	    return 0;
	  }
	}
      }
    }
  }
  else{
    for(k = 0; k < 10; k++){
      char c1 = strings[k][0];
      if((c1 >= 'a' && c1 <= 'z') || (c1 >= 'A' && c1 <= 'Z')){
	if(strcmp(strings[k], "return")){
	  if(get_offset(strings[k], m) == 0){
	    printf("The variable %s used in line %d has not been initialized.\n", strings[k], lineNum);
	    return 0;
	  }
	}
      }
    }
  }
  return 1;
}


