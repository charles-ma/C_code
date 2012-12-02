#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Please enter the name of the file to compile!\n");
    exit(0);
  }

  create_symbol_table(argv[1]);

  printf("===============================\n");

  iterate();
}
