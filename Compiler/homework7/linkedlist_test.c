
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TEST 1 - ADD A NEW NODE 
functions tested: add_node
*/
int test1() 
{
  printf("Test 1. Adding node with name ONE and offset 1\n");
  int retVal = add_node("ONE", 1);
  if (retVal != 1) {
    printf("ERROR! add_node function returned %d when it should have returned 1.\n", retVal);
    return 1;
  }

  printf("Test 1 passed!\n\n");
  return 0;
}


/*
TEST 2 - ADD A NEW NODE AND GET THE VALUE OF THE NODE BY ITS NAME
functions tested: add_node, getOffset
*/
int test2()
{
  printf("Test 2. Adding node with name TWO and offset 2\n");
  int retVal = add_node("TWO", 2);
  if (retVal != 1) {
    printf("ERROR! add_node function returned %d when it should have returned 1.\n", retVal);
    return 1;
  }

  int value;
  int *p = &value;
  printf("Test 2. Getting value of node with name TWO\n");
  retVal = get_offset("TWO", p);
  if (*p != 2) {
    printf("ERROR! value of node TWO came back as %d when it should have been 2.\n", *p);
    return 1;
  }
  else if (retVal != 1) {
    printf("ERROR! get_offset function returned %d when it should have returned 1.\n", retVal);
    return 1;
  }

  printf("Test 2 passed!\n\n");
  return 0;
}



/*
TEST 3 - ADD A BUNCH OF NODES, GET THE VALUE OF ONE OF THE MIDDLE ONES BY ITS NAME
functions tested: add_node, get_offset
*/
int test3()
{
  printf("Test 3. Adding nodes THREE, FOUR, FIVE, SIX\n");
  add_node("THREE", 3);
  add_node("FOUR", 4);
  add_node("FIVE", 5);
  add_node("SIX", 6);

  // now let's see if we can get the value of FOUR
  printf("Test 3. Getting offset of node with name FOUR\n");
  int value;
  int *p = &value;
  int retVal = get_offset("FOUR", p);
  if (*p != 4) {
    printf("ERROR! value of node FOUR came back as %d when it should have been 4.\n", *p);
    exit(1);
  }
  else if (retVal != 1) {
    printf("ERROR! get_offset function returned %d when it should have returned 1.\n", retVal);
    exit(1);
  }

  printf("Test 3 passed!\n\n");
  return 0;
}

main()
{
  printf("\n");

  if (test1()) exit(1);

  if (test2()) exit(1);

  if (test3()) exit(1);
  
  printf("\nALL TESTS PASSED!\n");
  
}
