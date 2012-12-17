#include <stdio.h>
#include <stdlib.h>

// so you can call this function from here
extern char* trim(char*);
extern FILE* open_file(char*);
extern int tokenize(char*, char*[]);

/*
 * Generate the prologue for the function and write it
 * to the output file.
 * Use the function header to determine the name of the
 * function, and use it as the label of the first
 * instruction of the prologue.
 */
int generate_prologue(char *header, FILE *f){

  int loc = 0;
  int para = 0;
  iterate(&loc, &para);

  fprintf(f, "%s ADD SP, SP, -1; push return value\nADD SP, SP, -1; push return address\nSTR R7, SP, 0\nADD SP, SP, -1; push frame pointer\nSTR FP, SP, 0\nADD FP, SP, -1; set frame pointer\n", header);
  int i = 0;
  for(; i < loc; ++i) fprintf(f, "ADD SP, SP, -1; push local variable\n");
}

/*
 * Convert this line of code to LC-3 and write to
 * the output file.
 */
int compile_line(char *line, FILE *f) {

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

  char *destin;
  char *next;
  int *offset = malloc(sizeof(int));
  int conNum;

  int charNum = tokenize(line, strings);
  
  if(strcmp(strings[0], "int") == 0){//it is a declaration statement
    fprintf(f, ";;%s", line);
    int i = 0;
    int flag = 0;
    for(; i < 10; ++i){
      if(strcmp(strings[i], "=") == 0){
	flag = 1;
      }
    }
    if(flag){//declaration and assignment
      int a1 = 0;
      for(; a1 < 10; ++a1){
	if(strcmp(strings[a1], "=") == 0){
	  destin = strings[a1 - 1];//the destination of the assignment
	  next = strings[a1 + 1];
	  if(is_letter(next[0])){//the next symbol is a variable
	    get_offset(next, offset);
	    //      printf("%d", *offset);
	    fprintf(f, "LDR R0, FP, %d; read %s\n", *offset, next);
	  }else if(next[0] >= 48 && next[0] <= 57){//the next symbol is a number
	    conNum = atoi(next);
	    fprintf(f, "AND R0, R0, 0; clear R0\n");
	    int b1 = 0;
	    for(;b1 < conNum / 15; ++b1)
	      fprintf(f, "ADD R0, R0, 15\n");
	    fprintf(f, "ADD R0, R0, %d; add constant number %d to R0\n", conNum % 15, conNum);
	    //printf("%d", conNum);
	  }
	  int c1 = 0;
	  for(c1 = a1 + 2; c1 < 10; ++c1){//find the operators(+ or -)
	    if(strcmp(strings[c1], "+") == 0){//the operator is +
	      next = strings[c1 + 1];
	      if(next[0] >= 48 && next[0] <= 57){//the next operand is a number
		conNum = atoi(next);
		int d1 = 0;
		for(; d1 < conNum / 15; ++d1)
		  fprintf(f, "ADD R0, R0, 15\n");
		fprintf(f, "ADD R0, R0, %d; add constant number %d to R0\n", conNum % 15, conNum);
	      }else{
		get_offset(next, offset);
		fprintf(f, "LDR R1, FP, %d; read %s\nADD R0, R0, R1; put sum in R0\n", *offset, next);
	      }
	      ++c1;
	    }else if(strcmp(strings[c1], "-") == 0){//the operator is -
	      next = strings[c1 + 1];
	      if(next[0] >= 48 && next[0] <= 57){//the next operand is a number
		conNum = atoi(next);
		int e1 = 0;
		for(; e1 < conNum / 16; ++e1)
		  fprintf(f, "ADD R0, R0, -16\n");
		fprintf(f, "ADD R0, R0, -%d; subtract constant number %d from R0\n", conNum % 16, conNum);
	      }else{//the next operand is a variable
		get_offset(next, offset);
		fprintf(f, "LDR R1, FP, %d; read %s\nNOT R1, R1\nADD R1, R1, 1; reverse %s\nADD R0, R0, R1; put sum in R0\n", *offset, next, next);
	      }
	      ++c1;
	    }else{break;}
	  }
	  get_offset(destin, offset);
	  fprintf(f, "STR R0, FP, %d; write %s\n", *offset, destin);
	  //	  printf("assignment to %s\n", destin);
	}
      }
      //      printf("declaration and assignment!\n");
    }else{//declaration
      //      printf("pure declaration!\n");
    }
  }else if(strcmp(strings[0], "return") == 0){//return
    fprintf(f, ";;%s", line);
    int a2 = 0;
    for(; a2 < 10; ++a2){
      if(strcmp(strings[a2], "return") == 0)
	break;
    }
    next = strings[a2 + 1];
    if(is_letter(next[0])){//the next symbol is a variable
      get_offset(next, offset);
      //      printf("%d", *offset);
      fprintf(f, "LDR R0, FP, %d; read %s\n", *offset, next);
    }else if(next[0] >= 48 && next[0] <= 57){//the next symbol is a number
      conNum = atoi(next);
      fprintf(f, "AND R0, R0, 0; clear R0\n");
      int b2 = 0;
      for(;b2 < conNum / 15; ++b2)
	fprintf(f, "ADD R0, R0, 15\n");
      fprintf(f, "ADD R0, R0, %d; add constant number %d to R0\n", conNum % 15, conNum);
      //printf("%d", conNum);
    }
    int c2 = 0;
    for(c2 = a2 + 1; c2 < 10; ++c2){//find the operators(+ or -)
      if(strcmp(strings[c2], "+") == 0){//the operator is +
	next = strings[c2 + 1];
	if(next[0] >= 48 && next[0] <= 57){//the next operand is a number
	  conNum = atoi(next);
	  int d2 = 0;
	  for(; d2 < conNum / 15; ++d2)
	    fprintf(f, "ADD R0, R0, 15\n");
	  fprintf(f, "ADD R0, R0, %d; add constant number %d to R0\n", conNum % 15, conNum);
	}else{
	  get_offset(next, offset);
	  fprintf(f, "LDR R1, FP, %d; read %s\nADD R0, R0, R1; put sum in R0\n", *offset, next);
	}
      }else if(strcmp(strings[c2], "-") == 0){//the operator is -
	next = strings[c2 + 1];
	if(next[0] >= 48 && next[0] <= 57){//the next operand is a number
	  conNum = atoi(next);
	  int e2 = 0;
	  for(; e2 < conNum / 16; ++e2)
	    fprintf(f, "ADD R0, R0, -16\n");
	  fprintf(f, "ADD R0, R0, -%d; subtract constant number %d from R0\n", conNum % 16, conNum);
	}else{//the next operand is a variable
	  get_offset(next, offset);
	  fprintf(f, "LDR R1, FP, %d; read %s\nNOT R1, R1\nADD R1, R1, 1; reverse %s\nADD R0, R0, R1; put sum in R0\n", *offset, next, next);
	}
      }
    }
    fprintf(f, "STR R0, FP, 3; write RV\n");
    //    printf("return!\n");
  }else if(is_letter(strings[0][0])){//assignment
    fprintf(f, ";;%s", line);
    int a = 0;
    for(; a < 10; ++a){
      if(strcmp(strings[a], "=") == 0)
	break;
    }
    destin = strings[a - 1];//the destination of the assignment
    next = strings[a + 1];
    if(is_letter(next[0])){//the next symbol is a variable
      get_offset(next, offset);
      //      printf("%d", *offset);
      fprintf(f, "LDR R0, FP, %d; read %s\n", *offset, next);
    }else if(next[0] >= 48 && next[0] <= 57){//the next symbol is a number
      conNum = atoi(next);
      fprintf(f, "AND R0, R0, 0; clear R0\n");
      int b = 0;
      for(;b < conNum / 15; ++b)
	fprintf(f, "ADD R0, R0, 15\n");
      fprintf(f, "ADD R0, R0, %d; add constant number %d to R0\n", conNum % 15, conNum);
      //printf("%d", conNum);
    }
    int c = 0;
    for(c = a + 1; c < 10; ++c){//find the operators(+ or -)
      if(strcmp(strings[c], "+") == 0){//the operator is +
	next = strings[c + 1];
	if(next[0] >= 48 && next[0] <= 57){//the next operand is a number
	  conNum = atoi(next);
	  int d = 0;
	  for(; d < conNum / 15; ++d)
	    fprintf(f, "ADD R0, R0, 15\n");
	  fprintf(f, "ADD R0, R0, %d; add constant number %d to R0\n", conNum % 15, conNum);
	}else{
	  get_offset(next, offset);
	  fprintf(f, "LDR R1, FP, %d; read %s\nADD R0, R0, R1; put sum in R0\n", *offset, next);
	}
      }else if(strcmp(strings[c], "-") == 0){//the operator is -
	next = strings[c + 1];
	if(next[0] >= 48 && next[0] <= 57){//the next operand is a number
	  conNum = atoi(next);
	  int e = 0;
	  for(; e < conNum / 16; ++e)
	    fprintf(f, "ADD R0, R0, -16\n");
	  fprintf(f, "ADD R0, R0, -%d; subtract constant number %d from R0\n", conNum % 16, conNum);
	}else{//the next operand is a variable
	  get_offset(next, offset);
	  fprintf(f, "LDR R1, FP, %d; read %s\nNOT R1, R1\nADD R1, R1, 1; reverse %s\nADD R0, R0, R1; put sum in R0\n", *offset, next, next);
	}
      }
    }
    get_offset(destin, offset);
    fprintf(f, "STR R0, FP, %d; write %s\n", *offset, destin);
    //    printf("assignment to %s\n", destin);
  }else{//other
    //    printf("unknown!\n");
  }
  //  printf("Compile %s\n", line);

}

/*
 * Generate the epilogue for this function.
 */
int generate_epilogue(FILE *f) {
  int loc = 0;
  int para = 0;
  iterate(&loc, &para);
  fprintf(f, ";; epilogue\n");
  int i = 0;
  for(; i < loc; ++i) fprintf(f, "ADD SP, SP, 1; pop local variable\n");
  fprintf(f, "STR FP, SP, 0; pop frame pointer\nADD SP, SP, 1\nSTR R7, SP, 0; pop return address\nADD SP, SP, 1\nADD SP, SP, 1; pop return value\n");
  for(i = 0; i < para; ++i) fprintf(f, "ADD SP, SP, 1; pop parameter\n");  
  fprintf(f, "RET; done!\n");
}

main(int argc, char *argv[]) {

  // make sure the filename is specified
  if (argc < 2) {
    printf("Please specify the name of the file to compile\n");
    return;
  }
  char *name  = argv[1];
  char funName[20];
  char newFileName[20];
  char line[110];

  // create the symbol table
  if (create_symbol_table(name, funName) == 0) {
    exit(0);
  }

  // create the target file
  int i = 0;
  while(name[i] != '.'){
    newFileName[i] = name[i];
    i++;
  }
  newFileName[i] = '.';
  newFileName[i + 1] = 'l';
  newFileName[i + 2] = 'c';
  newFileName[i + 3] = '3';
  newFileName[i + 4] = '\0';
  FILE *output = fopen(newFileName, "w");
  if(output == NULL) exit(0);

  //compile the file
  FILE *infile = open_file(name);
  fgets(line, 110, infile);
  generate_prologue(funName, output);
  while(!feof(infile)){
    fgets(line, 110, infile);
    compile_line(line, output);
  }
  generate_epilogue(output);

}
