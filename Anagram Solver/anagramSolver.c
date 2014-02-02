#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//the node of the linked list
typedef struct Node {
  char* data;
  struct Node* next;
} Node;

Node** createDic();
void findAnagram(char*, Node**);
int isAnagram(char*, char*);
int getHashNum(char);

//main function
int main(int argc, char** argv) {
  
  Node** dict = createDic();  

  char a[128];
  scanf("%s", a);
  findAnagram(a, dict);
  int i = 0;
  for(; i < 2000; i++) {
    if(dict[i] != NULL){ 
      Node* tmp = dict[i];
      Node* tmp1 = NULL;
      while(tmp != NULL){
	free(tmp -> data);
	tmp1 = tmp;
	tmp = tmp -> next;
	free(tmp1);
      }
    }
  }
  free(dict);
}

//find all the anagrams of a given string
void findAnagram(char* in, Node** dict) {
  if(in == NULL) return;
  int i = 0;
  int hashNum = 0;
  while(in[i] != '\0') {
    hashNum += getHashNum(in[i]);
    i++;
  }
  Node* node = dict[hashNum];
  while(node != NULL) {
    if(isAnagram(in, node -> data)) printf("%s\n", node -> data);
    node = node -> next;
  }
}

//test wheter two strings are anagrams
int isAnagram(char* a, char* b) {
  if(strlen(a) != strlen(b)) return 0;
  if(strcmp(a, b) == 0) return 0;
  int tmp[27];
  int i = 0;
  int flag = 0;
  for(; i < strlen(a); i++) {
    if(a[i] == b[i] || a[i] == b[i] + 32 || a[i] == b[i] - 32);
    else {
      flag = 1;
      break;
    }
  }
  if(flag == 0) return 0;
  i = 0;
  for(; i < 27; i++) tmp[i] = 0;
  i = 0;
  for(; i < strlen(a); i++) {
    tmp[getHashNum(a[i])] += 1;
  }
  i = 0;
  for(; i < strlen(b); i++) {
    tmp[getHashNum(b[i])] -= 1;
  }
  i = 1;
  for(; i < 27; i++) {
    if(tmp[i] != 0) return 0;
  }
  return 1;
}

//caculate the hash code for a letter
int getHashNum(char a) {
  if('a' <= a && 'z' >= a) return a - 96;
  if('A' <= a && 'Z' >= a) return a - 64;
  else return 0;
}

//create the dictionary from the given file
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
    while(word[i] != '\n') {
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
}
