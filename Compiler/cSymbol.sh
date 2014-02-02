cc -o symboltabletest symboltable_test.c symboltable.c linkedlist.c find_symbols.c tokenize.c
./symboltabletest testcase.txt
./symboltabletest badInput1.txt
./symboltabletest badInput2.txt
./symboltabletest badInput3.txt
./symboltabletest badInput4.txt