# CC = Your compiler
CC=gcc

# CFLAGS = CompilatorFLAGS
CFLAGS=-c

all: program

program: main.o solve.o
	$(CC) main.o solve.o -o program -lm

debug: solve.o test.o
	$(CC) solve.o test.o -o debug -lm

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

solve.o: solve.cpp
	$(CC) $(CFLAGS) solve.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

clean:
	rm -rf *.o program debug

