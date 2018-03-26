all:program10
program10:	program10.o Hash.o
	gcc -g program10.o Hash.o -o program10
program10.o:	program10.c
	gcc -g -c program10.c
Hash.o:	Hash.c
	gcc -g -c Hash.c
checkmem:	program10
	valgrind -v ./program10
run:	program10
	./program10
clean:
	rm -rf *.o program10