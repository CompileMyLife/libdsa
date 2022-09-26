CC=gcc
CFLAGS=-std=c99 -Wall

all: Test

Test: lists.o
	$(CC) $(CFLAGS) main.c $< -o $@

lists.o: lists.h lists.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o *.h.gch Test
