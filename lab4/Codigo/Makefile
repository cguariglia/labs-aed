#  Compiler
CC = gcc

#  Compiler Flags
CFLAGS = -g -Wall -pedantic

# dependencies
DEP1 = defs.h lab4a.c maina.c
DEP2 = defs.h lab4b.c mainb.c 

OBJ1 = lab4a.o maina.o
OBJ2 = lab4b.o mainb.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

p1: $(OBJ1)
	$(CC) $(CFLAGS) -o p1 $(OBJ1)

p2: $(OBJ2)
	$(CC) $(CFLAGS) -o p2 $(OBJ2)

clean:
	rm -f *.o p1 p2 *~
