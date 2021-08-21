# CC = Your compiler
CC=gcc

# CFLAGS = CompilatorFLAGS
CFLAGS=-c

all: program

program: main.o solve.o
	$(CC) main.o solve.o -o program -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

solve.o: solve.c
	$(CC) $(CFLAGS) solve.c

clean:
	rm -rf *.o program

