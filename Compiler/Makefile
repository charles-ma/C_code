all:	linkedlist_test	symboltable_test

linkedlist_test:
	cc -o linkedlisttest linkedlist_test.c linkedlist.c tokenize.c

symboltable_test:
	cc -o symboltabletest symboltable_test.c symboltable.c linkedlist.c tokenize.c find_symbols.c

clean:
	rm linkedlisttest symboltabletest
