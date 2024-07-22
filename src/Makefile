CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

# Targets
all: main

main: main.o matrix.o
	$(CC) $(CFLAGS) main.o matrix.o -o main -lm

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c -lm

main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main