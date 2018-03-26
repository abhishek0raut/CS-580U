all:program6
program6:	program6.o bst.o
	gcc -g program6.o bst.o -o program6
program6.o:	program6.c
	gcc -g -c program6.c
bst.o:	bst.c
	gcc -g -c bst.c
checkmem:	program6
	valgrind -v ./program6
run:	program6
	./program6
clean:
	rm -rf *.o program6