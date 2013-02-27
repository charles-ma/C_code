#include "Animal.h"
#include "Lion.h"
#include "Tiger.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

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

}
