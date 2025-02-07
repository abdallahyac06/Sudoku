CC = g++
CFLAGS = -Wall -g

all: main

main: main.o sudoku.o
	$(CC) $(CFLAGS) -o main main.o sudoku.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

sudoku.o: sudoku.cpp
	$(CC) $(CFLAGS) -c sudoku.cpp

clean:
	rm -f *.o main