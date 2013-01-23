#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char* data;
  struct Node* next;
} Node;

Node** createDic();

int main(int argc, char** argv) {
  Node** dict = createDic();
  int i = 0;
  for(; i < 2000; i++) {

    Node* node = NULL;
    if(dict[i] != NULL) {
      node = dict[i];
      printf("The sum is %d.\n", i);
    }
    while(node != NULL) {
      printf("%s", node -> data);
      node = node -> next;
    }
    if(dict[i] != NULL) printf("__________\n");
  }
}

int getHashNum(char a) {
  if('a' <= a && 'z' >= a) return a - 96;
  if('A' <= a && 'Z' >= a) return a - 64;
  else return 0;
}

Node** createDic() {
  //read in the file "/usr/share/dict/words", which exits in all Unix like system
  FILE* dict = fopen("/usr/share/dict/words", "r");
  if(dict == NULL) return;

  //malloc space for the new dictionary and initialize all the elements in it as NULL
  Node** dic = (Node**)malloc(2000 * sizeof(Node*));
  int k = 0;
  for(; k < 2000; k++) dic[k] = NULL;

  //malloc space for all the strings in the words file of Unix like system and read in this file
  char word[128];
  while(fgets(word, sizeof(word), dict) != NULL) {
    int i = 0;
    int hashNum = 0;
    char* word1 = (char*) malloc(128 * sizeof(char));
    while(word[i] != '\0') {
      hashNum += getHashNum(word[i]);
      word1[i] = word[i];
      i++;
    }
    word1[i] = '\0';
    //    printf("%d\n", hashNum);
    Node* newHead = (Node*)malloc(sizeof(Node));
    newHead -> data = word1;
    newHead -> next = dic[hashNum];
    dic[hashNum] = newHead;
  }

  return dic;

  /*  Node* a = dic[22];
  while(a != NULL) {
    printf("%s", a -> data);
    a = a -> next;
    }*/
}

