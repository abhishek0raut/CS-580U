all: defuseTheBomb.o checkmem.o

defuseTheBomb.o: bomb.o defuseMe.o hidden.o
	gcc bomb.o defuseMe.o hidden.o -o bomb

bomb.o: bomb.c

defuseMe.o: defuseMe.c

checkmem.o: program3B.c
	gcc program3B.c -o checkmem

clean:
	chmod +x ./trash.sh *.o