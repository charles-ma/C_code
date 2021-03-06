#define LENGTH 12
/*
  Rule 1: The first digit must be a 4
*/
int checkRule1 (int cardNumber[]) {
  if(cardNumber[0] == 4) return 1;
  return 0;
}

/*
  Rule 2: If the third digit is even, the fourth digit must be odd
  If the third digit is odd, the fourth digit must be even
*/
int checkRule2 (int cardNumber[]) {
  if((cardNumber[2] + cardNumber[3]) % 2 != 0) return 1;
  return 0;
}
  

/*
  Rule 3: The fourth digit must be one greater than the fifth digit  
*/
int checkRule3 (int cardNumber[]) {
  if(cardNumber[3] - 1 == cardNumber[4]) return 1;
  return 0;
}


/* 
   Rule 4: The second digit must either be a zero or equal to the sum of the
   ninth and tenth digits
 */  
int checkRule4 (int cardNumber[]) {
  if(cardNumber[1] == 0 || cardNumber[1] == cardNumber[8] + cardNumber[9]) return 1;
  return 0;
}



/*
  Rule 5: The product of the first, fifth, and ninth digits must be 24  
*/
int checkRule5 (int cardNumber[]) {
  if(cardNumber[0] * cardNumber[4] * cardNumber[8] == 24) return 1;
  return 0;
}


/*
  Rule 6: The sum of all digits must be evenly divisible by 4   
*/
int checkRule6 (int cardNumber[]) {
  int i, sum = 0;
  for(i = 0; i < LENGTH; ++i) sum += cardNumber[i];
  if(sum % 4 == 0) return 1;
  return 0;
}


/* 
   Rule 7: The sum of the first four digits must be one less than the sum 
   of the last four digits
 */  
int checkRule7 (int cardNumber[]) {
  int i, sum1 = 0, sum2 = 0;
  for(i = 0; i < 4; ++i){
    sum1 += cardNumber[i];
    sum2 += cardNumber[LENGTH -1 - i];
  }
  if(sum2 - sum1 == 1) return 1;
  return 0;
}


/* 
   Rule 8: If you treat the first two digits as a two-digit number, and 
   the seventh and eighth digits as a two digit number, their sum must be 100
 */  
int checkRule8 (int cardNumber[]) {
  int num1, num2;
  num1 = cardNumber[0] * 10 + cardNumber[1];
  num2 = cardNumber[6] * 10 + cardNumber[7];
  if(num1 + num2 == 100) return 1;
  return 0;
}


/* 
   Rule 9: If you treat the last two digits as a two-digit number, it must
   not be prime.
 */
int checkRule9 (int cardNumber[]) {
  int num;
  num = cardNumber[LENGTH - 2] * 10 + cardNumber[LENGTH - 1];
  int i;
  for(i = 2; i < num / 2; ++i){
    if(num % i == 0) return 1;
  }
  return 0;
}


/*
  All the rules above must be satisfied to be a valid card number
*/
int checkCreditCard (int cardNumber[]) {
  return checkRule1(cardNumber) * checkRule2(cardNumber) * checkRule3(cardNumber) * checkRule4(cardNumber) * checkRule5(cardNumber) * checkRule6(cardNumber) * checkRule7(cardNumber) * checkRule8(cardNumber) * checkRule9(cardNumber);
}
  

