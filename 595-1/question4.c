#include <stdio.h>
#include <stdlib.h>

void sort(int * a, int);
typedef struct ListNode {
  int data;
  struct ListNode * next;
}ListNode;

//sort the linked list
void sortLinkedList(ListNode * head){
  int i = 0;
  ListNode * curr = head;
  while(curr != NULL){
    i++;
    curr = curr->next;
  }
  int tmpArray[i];
  i = 0;
  curr = head;
  while(curr != NULL){
    tmpArray[i] = curr->data;
    curr = curr->next;
    i++;
  }
  sort(tmpArray, i);
  curr = head;
  int j = 0;
  for(; j < i; j++){
    curr->data = tmpArray[j];
    curr = curr->next;
  }
}
