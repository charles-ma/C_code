/* Test whether the functions in creditcardchecker are correct 
 */
#include <stdio.h>

extern int checkRule1 (int cardNumber[]);
extern int checkRule2 (int cardNumber[]);
extern int checkRule3 (int cardNumber[]);
extern int checkRule4 (int cardNumber[]);
extern int checkRule5 (int cardNumber[]);
extern int checkRule6 (int cardNumber[]);
extern int checkRule7 (int cardNumber[]);
extern int checkRule8 (int cardNumber[]);
extern int checkRule9 (int cardNumber[]);
extern int checkCreditCard(int cardNumber[]);

/*
  Rule 1: The first digit must be a 4.

  This one is already done for you!
*/
void testRule1() {
  //This is the input we think will succeed
  int goodInput[] = {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule1; we're expecting to get a 1 back 
  if (checkRule1(goodInput) == 1)
    printf("checkRule1: test 1 passed\n");
  else printf("checkRule1: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule1; we're expecting to get a 0 back
  if (checkRule1(badInput) == 0)
    printf("checkRule1: test 2 passed\n");
  else printf("checkRule1: TEST 2 FAILED\n");
}


/*
  Rule 2: If the third digit is even, the fourth digit must be odd
  If the third digit is odd, the fourth digit must be even
*/
void testRule2() {
  //This is the input we think will succeed
  int goodInput[] = {0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule2; we're expecting to get a 1 back 
  if (checkRule2(goodInput) == 1)
    printf("checkRule2: test 1 passed\n");
  else printf("checkRule2: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule2; we're expecting to get a 0 back
  if (checkRule2(badInput) == 0)
    printf("checkRule2: test 2 passed\n");
  else printf("checkRule2: TEST 2 FAILED\n");
}

/*
  Rule 3: The fourth digit must be one greater than the fifth digit  
*/
void testRule3() {
  //This is the input we think will succeed
  int goodInput[] = {4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule3; we're expecting to get a 1 back 
  if (checkRule3(goodInput) == 1)
    printf("checkRule3: test 1 passed\n");
  else printf("checkRule3: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule3; we're expecting to get a 0 back
  if (checkRule3(badInput) == 0)
    printf("checkRule3: test 2 passed\n");
  else printf("checkRule3: TEST 2 FAILED\n");
}

/* 
   Rule 4: The second digit must either be a zero or equal to the sum of the
   ninth and tenth digits
 */  
void testRule4() {
  //This is the input we think will succeed
  int goodInput[] = {4, 3, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0};
  int goodInput1[] = {4, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0};
  // Called checkRule4; we're expecting to get a 1 back 
  if (checkRule4(goodInput) == 1 && checkRule4(goodInput1) == 1)
    printf("checkRule4: test 1 passed\n");
  else printf("checkRule4: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule4; we're expecting to get a 0 back
  if (checkRule4(badInput) == 0)
    printf("checkRule4: test 2 passed\n");
  else printf("checkRule4: TEST 2 FAILED\n");
}

/*
  Rule 5: The product of the first, fifth, and ninth digits must be 24  
*/
void testRule5() {
  //This is the input we think will succeed
  int goodInput[] = {4, 0, 0, 0, 1, 0, 0, 0, 6, 0, 0, 0};
  // Called checkRule5; we're expecting to get a 1 back 
  if (checkRule5(goodInput) == 1)
    printf("checkRule5: test 1 passed\n");
  else printf("checkRule5: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule5; we're expecting to get a 0 back
  if (checkRule5(badInput) == 0)
    printf("checkRule5: test 2 passed\n");
  else printf("checkRule5: TEST 2 FAILED\n");
}


/*
  Rule 6: The sum of all digits must be evenly divisible by 4
*/
void testRule6() {
  //This is the input we think will succeed
  int goodInput[] = {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule6; we're expecting to get a 1 back
  if (checkRule6(goodInput) == 1)
    printf("checkRule6: test 1 passed\n");
  else printf("checkRule6: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule6; we're expecting to get a 0 back
  if (checkRule6(badInput) == 0)
    printf("checkRule6: test 2 passed\n");
  else printf("checkRule6: TEST 2 FAILED\n");
}


/* 
   Rule 7: The sum of the first four digits must be one less than the sum 
   of the last four digits
 */  
void testRule7() {
  //This is the input we think will succeed
  int goodInput[] = {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0};
  // Called checkRule7; we're expecting to get a 1 back 
  if (checkRule7(goodInput) == 1)
    printf("checkRule7: test 1 passed\n");
  else printf("checkRule7: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule7; we're expecting to get a 0 back
  if (checkRule7(badInput) == 0)
    printf("checkRule7: test 2 passed\n");
  else printf("checkRule7: TEST 2 FAILED\n");
}


/* 
   Rule 8: If you treat the first two digits as a two-digit number, and 
   the seventh and eighth digits as a two digit number, their sum must be 100
 */  
void testRule8() {
  //This is the input we think will succeed
  int goodInput[] = {4, 6, 0, 0, 0, 0, 5, 4, 0, 0, 0, 0};
  // Called checkRule8; we're expecting to get a 1 back 
  if (checkRule8(goodInput) == 1)
    printf("checkRule8: test 1 passed\n");
  else printf("checkRule8: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule8; we're expecting to get a 0 back
  if (checkRule8(badInput) == 0)
    printf("checkRule8: test 2 passed\n");
  else printf("checkRule8: TEST 2 FAILED\n");
}

/* 
   Rule 9: If you treat the last two digits as a two-digit number, it must
   not be prime.
 */
void testRule9() {
  //This is the input we think will succeed
  int goodInput[] = {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
  // Called checkRule9; we're expecting to get a 1 back 
  if (checkRule9(goodInput) == 1)
    printf("checkRule9: test 1 passed\n");
  else printf("checkRule9: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // Called checkRule9; we're expecting to get a 0 back
  if (checkRule9(badInput) == 0)
    printf("checkRule9: test 2 passed\n");
  else printf("checkRule9: TEST 2 FAILED\n");
}
  


/*
  check that all rules are satisfied for a good card number
*/
void testCheckCredit() {
  //This is the input we think will succeed
  int goodInput[] = {4, 8, 0, 7, 6, 0, 5, 2, 1, 7, 6, 6};
  int goodInput1[] = {4, 0, 9, 4, 3, 4, 6, 0, 2, 7, 5, 4};
  // Called checkCreditCard; we're expecting to get a 1 back 
  if (checkCreditCard(goodInput) == 1 && checkCreditCard(goodInput1) == 1)
    printf("checkCreditCard: test 1 passed\n");
  else printf("checkCreditCard: TEST 1 FAILED\n");

  //This is the input we think will fail
  int badInput[] = {4, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0};
  // Called checkCreditCard; we're expecting to get a 0 back
  if (checkCreditCard(badInput) == 0)
    printf("checkCreditCard: test 2 passed\n");
  else printf("checkCreditCard: TEST 2 FAILED\n");
}

main()
{
  testRule1();
  testRule2();
  testRule3();
  testRule4();
  testRule5();
  testRule6();
  testRule7();
  testRule8();
  testRule9();
  testCheckCredit();
}
