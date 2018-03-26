all:program5
program5:	program5.o vector.o list.o profile.o
	gcc -g program5.o vector.o list.o profile.o -o program5
program5.o:	program5.c
	gcc -g -c program5.c
vector.o:	vector.c
	gcc -g -c vector.c
list.o:         list.c
	gcc -g -c list.c
profile.o:	profile.c
	gcc -g -c profile.c
checkmem:	program5
	valgrind -v ./program5
run:	program5
	./program5
clean:
	rm -rf *.o program5