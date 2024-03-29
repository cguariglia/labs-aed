/*
 * lab4a.c
 * 
 * Copyright 2016 Unknown <menrva@thered>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "lab4a.h"




// also initalizes matrix
void readMatrix(FILE *input, graph *output) {
	int i, j, size, edges=0;
	
	
	fscanf(input, "%d", &size);
	
	output->edges = 0;
	output->vertices = 0; 	
	output->matrix = (int **)malloc(size * sizeof(int *));

	if(output->matrix == NULL)
		exit(1);
	
	for(i = 0; i < size; i++) {
		output->matrix[i] = (int *)malloc(size * sizeof(int));
		if(output->matrix[i] == NULL)
			exit(1);
	}
	
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
		  fscanf(input, "%d",&output->matrix[i][j]);
		  if(output->matrix[i][j] > 0)
			edges++;
		}
	}

	output->edges = edges/2;
	output->vertices = size; // MAYBE I'M NOT SURE I ACTUALLY DIDN'T GET THAT R:. It good Carolina Maria
	return;
	
}
void printDensity(graph g) {
	
	printf("Density of graph: %f\n", ((2.0 * g.edges)/g.vertices));
	
	return;
}

void printMaxDegree(graph g, int size) {
	int i, j, sum, degree = 0;
	
	for(i = 0; i < size; i++) {
		sum = 0;
		
		for(j = 0; j < size; j++)
			if(g.matrix[i][j] != 0)
				sum++;
			
		if(sum > degree)
			degree = sum;
	}
	
	printf("Max degree of the graph: %d\n", degree);
	
	return;
}

// copiadíssimo do projeto
char* outputFileExtention(char * name_input){
	char *name_output, *dot;
	
	name_output = (char *)malloc(strlen(name_input) + 2);
	if(name_output == NULL)
		exit(1);
	
	dot = strrchr(name_input, '.');
	
	*dot = '\0';
	
	strcat(name_input, ".ram");
	strcpy(name_output, name_input);
	
	return name_output;
}


void printOutFile(FILE *output, graph g){

	int i=0, j=0;
	fprintf(output, "%d\n",g.vertices);
	fprintf(output, "%d\n",g.edges);

	for(i = 0; i < g.vertices; i++) {

		for(j = 0; j < i; j++) {
		
			if(g.matrix[i][j]!=0)
				fprintf(output, "%d %d %d\n",j, i, g.matrix[i][j]);
		}
			 
	}
	
	return;
}
	
	
void writeFile(char *oldfile, graph g) {
	FILE *f;
	char *filename;
	
	filename = outputFileExtention(oldfile);
	
	f = fopen(filename, "w");
	if(f == NULL)
		exit(1);
		
	
    printOutFile(f,g);
    
	fclose(f);
	free(filename);
	
	return;
}

void freeMatrix(graph *g) {
	int i;
	
	for(i = 0; i < g->vertices; i++)
		free(g->matrix[i]);
		
	free(g->matrix);
	
	return;
}
