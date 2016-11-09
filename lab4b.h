#ifndef LAB4B_H
#define LAB4B_H

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "LinkedList.h"



typedef struct _link link;

struct _link {
	int vertex;
	int weight;
	_link *next;
}

struct graph{
	int edges;
	int vertices;
	link **adj;
};



link *newLink(int v, link *next);
graph *initGraph(FILE *input);
void readMatrix(FILE *input, graph *output);
void blabla(graph *output, int valorv1,int valorv2, int vertices_num, int weight);


void writeFile(char *oldfile, graph g);
char* outputFileExtention(char * name_input);

#endif
