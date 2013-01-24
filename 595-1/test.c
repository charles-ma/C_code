#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int data;
  struct ListNode * next;
} ListNode;

void createArray();
void createStringArray();
void sort(int*, int);
void sortLinkedList(ListNode *);
void initializeArray(int);
void add(int);
void removeElement();
void get(int);
void destroyArray();

void main(){
  //test for createArray using malloc
  createArray();

  //test for createStringArray using malloc
  createStringArray();

  //test for sorting an array
  int a[10] = {5,3,4,2,1,6,9,10,15,5};
  sort(a,10);
  printf("\ntest for sorting an array\n");
  int i = 0;
  for(; i < 10; i++){
    printf("%d\n", a[i]);
  }

  //test for sorting a linked list 
  int j = 0;
  ListNode * head;
  ListNode * curr;
  ListNode * next;
  head = (ListNode *)malloc(sizeof(ListNode));
  head -> data = 0;
  curr = head;
  for(; j < 5; j++){
    next = (ListNode *)malloc(sizeof(ListNode));
    next -> data = 10 - j;
    next -> next = NULL;
    curr -> next = next;
    curr = next;
  }
  sortLinkedList(head);
  printf("\ntest for sorting a linkedlist\n");
  curr = head;
  while(curr != NULL){
    printf("%d\n", curr -> data);
    ListNode * pre = curr;
    curr = curr -> next;
    free(pre);
  }
  
  //test for realloc efficiency
  initializeArray(10);
  int k = 0;
  for(; k < 1000000; k++){
    add(k);
  }
  destroyArray();
}
