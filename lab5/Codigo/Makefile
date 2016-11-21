CC=gcc
CFLAGS=-g -c -Wall -ansi -pedantic

hashpal: hash.o pal.o
	$(CC) -g -o hashpal hash.o pal.o


hash.o: hash.c pal.h
	$(CC) $(CFLAGS) hash.c

pal.o: pal.c pal.h
	$(CC) $(CFLAGS) pal.c


etags::
	etags *.h *.c

clean::
	rm -f *.o core a.out *.palavras hashpal *~



