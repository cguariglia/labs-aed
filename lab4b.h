#ifndef LAB4B_H
#define LAB4B_H

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct _link {
	int vertex;
	int weight;
	struct _link *next;
} link;

typedef struct{
	int edges;
	int vertices;
	link **adj;
} graph;

link *newLink(int v, int w, link *next);
graph *initGraph(FILE *input);
void readMatrix(FILE *input, graph *output);
void insert(graph *output, int valorv1,int valorv2, int weight);

void writeFile(char *oldfile, graph *g);
char* outputFileExtention(char * name_input);

void printOutFile(FILE *output, graph *g);
void freeEverything(graph *g);

#endif
