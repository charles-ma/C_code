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

main(){
  char name[128], pw[128]; /* passwords are short! */
  char *good = "Welcome to The Machine!\n";
  char *evil = "Invalid identity, exiting!\n";
  /*long *ret;
  ret = pw - 0x10;
  
  printf("%lx\n", name);
  printf("%lx\n", pw);
  printf("%lx\n", &evil);
  printf("%lx\n", &good);
  printf("%lx\n", ret);
  (*ret) = good;*/

  printf("login: "); scanf("%s", name);
  printf("password: "); scanf("%s", pw);
  if (match(name, pw) == 0)
    welcome(good);
  else
    goodbye(evil);
}
	
