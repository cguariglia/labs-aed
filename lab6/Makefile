#
# Makefile for heap example
#

CC=gcc
TARGET=client
CFLAGS= -g -ansi -Wall -I.
LIBS= -lm

SRCFILES= client.c heap.c
INCFILES= heap.h Item.h
OBJFILES= client.o heap.o

default: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJFILES) core.* #*

heap.o: heap.c heap.h Item.h

client.o: client.c heap.h Item.h
