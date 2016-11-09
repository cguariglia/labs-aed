#ifndef LAB4A_H
#define LAB4A_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _graph{
	int edges;
	int vertices;
	int **matrix;
} graph;

void readMatrix(FILE *input, graph *output);
void printDensity(graph g);
void printMaxDegree(graph g, int size);
char* outputFileExtention(char * name_input);
void printOutFile(FILE *output, graph g);
void writeFile(char *oldfile, graph g);

#endif
