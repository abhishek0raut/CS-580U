all:program4
program4:	program4.o tournament.o
	gcc -g program4.o tournament.o -o program4
program4.o:	program4.c
	gcc -g -c program4.c
tournament.o:	tournament.c
	gcc -g -c tournament.c
checkmem:	program4
	valgrind -v ./program4
run:	program4
	./program4
clean:
	rm -rf *.o program4
