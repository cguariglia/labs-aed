#ifndef LAB4A_H
#define LAB4A_H

#include <stdio.h>
#include <stdlib.h>

void readMatrix(FILE *input, graph *output);
void printDensity(graph *g);
void printMaxDegree(graph *g, int size);
char* outputFileExtention(char * name_input);
void writeFile(char *oldfile);

#endif
