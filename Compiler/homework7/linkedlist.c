#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * DO NOT CHANGE THIS DEFINITION!
 */
typedef struct Node node;

struct Node {
  char name[10];
  int offset;
  node *next;
};

// global pointer to first Node of Linked List
struct Node *head = NULL;


/*
  Adds a new node to the linked list, with name set to parameter "s" and offset set to parameter "v".
  Returns 1 if successful, 0 if an error occurred.
*/
int add_node(char *s, int v)
{
  node *newNode = malloc(sizeof(node));
  strcpy(newNode -> name, s);
  newNode -> offset = v;
  newNode -> next = head;
  head = newNode;
  return 1;
}

/*
  Finds the offset of the node whose name is equal to the first argument.
  If the node is found, its offset value is put into the "v" parameter, and the function returns 1.
  If an error occurs (e.g. there is no node with that name), the function returns 0.
*/
int get_offset(char *s, int *v)
{
  node *currNode;
  currNode = head;
  while(currNode != NULL){
    if(strcmp(currNode -> name, s) == 0){
      *v = currNode -> offset;
      return 1;
    }
    currNode = currNode -> next;
  }
  return 0;
}

/*
 Print out (to the screen) the name and offset value for each node
 in the linked list.
*/
void iterate() 
{
  printf("All of the nodes are listed below:\n");
  node *currNode;
  currNode = head;
  while(currNode != NULL){
    printf("%s: %d\n", currNode -> name, currNode -> offset);
    currNode = currNode -> next;
  }
}

