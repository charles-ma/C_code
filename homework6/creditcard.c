#include <stdio.h>
#include <stdlib.h>
#define LENGTH 12

extern int checkCreditCard(int cardNumber[]);

int main(){
  printf("Please enter the credit card number(12 numbers):");
  char str[LENGTH + 1];
  int numbers[LENGTH];
  scanf("%s", str);
  if(str[LENGTH] != NULL){
    printf("Please enter 12 numbers!\n");
    return 0; 
  }
  int i;
  for(i = 0; i < LENGTH; ++i){
    if(str[i] < '0' || str[i] > '9'){
      printf("Please input 12 numbers!\n");
      return 0;
    }else{
      char s[2];
      s[0] = str[i];
      s[1] = NULL;
      numbers[i] = atoi(&s);
    } 
  }
  if(checkCreditCard(numbers)) printf("This card number is valid.\n");
  else printf("This card number is invalid.\n");
  return 1;
}
