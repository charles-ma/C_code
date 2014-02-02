#include <stdio.h>
#include <stdlib.h>
#define TIMES 1000000

extern int checkCreditCard(int cardNumber[]);

main(){
  srandom(time(0));
  int cardNumber[12] = {4};
  int i, j, count = 0;
  for(i = 0; i < TIMES; ++i){
    for(j = 1; j < 12; ++j){
      cardNumber[j] = random() % 10;
    }
    if(checkCreditCard(cardNumber)) ++count;
  }
  printf("The probability to guess the valid credit card number is %Lf\%\n", count * 100.0 / TIMES);
}
