# CC = Your compiler
CC=gcc

# CFLAGS = CompilatorFLAGS
CFLAGS=-c

all: program

program: main.o solve.o test.o
	$(CC) main.o solve.o test.o -o program -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

solve.o: solve.c
	$(CC) $(CFLAGS) solve.c

test.o: test.c
	$(CC) $(CFLAGS) test.c

clean:
	rm -rf *.o program

