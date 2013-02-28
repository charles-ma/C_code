#include "Animal.h"
#include "Lion.h"
#include "Tiger.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unistd.h"
#include "fcntl.h"
#include "sys/wait.h"

struct node {
  int value;
  struct node* next;
};

int main(int argc, char** argv) {
  Tiger tiger;
  Animal *ani = new Tiger((char*)"Mike", 3);

  printf("%s\n", argv[0]);
  char para[5];
  for(int i = 0; i < 5; i++) {
    printf("%d\n", para[i]);
  }
  strncpy(para, argv[0], 4);
  para[4] = '\0';
  printf("%s\n", para);

  tiger.makeSound();
  tiger.eat();

  ani -> makeSound();
  ani -> eat();

  delete ani;

  node *head = NULL;

  for(int i = 0; i < 100; i++) {
    node *linkedlist = new node();
    linkedlist -> value = i;
    linkedlist -> next = head;
    head = linkedlist;
  }

  while(head != NULL) {
    printf("%d\n", head -> value);
    node *pre = head;
    head = head -> next;
    free(pre);
  }


  int fd = open("./testInput.txt", O_RDWR | O_CREAT, 0766);
  //dup2(fd, 1);
  
  printf("%d\n", fd);
  char chars[10];
  int read_num = read(fd, chars, 9);
  chars[9] = '\0';
  
  printf("%d\n%s\n", read_num, chars);

  lseek(fd, -5, SEEK_CUR);
  
  write(fd, "this is newer", 14);

  int *i = new int;
  int pid = fork();
  if(pid == 0) {
    write(1, "Hello from child.\n", 18);
    int result = execl("/bin/date", "date", NULL);
    printf("%d\n", result);
    delete i;
    exit(0);
  } else {
    //waitpid(pid, i, 0);
    wait(i);
    write(1, "Hello form parent.\n", 19);
    delete i;
  } 

  
}
