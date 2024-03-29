/*
 * lab4b.c
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
#include "lab4b.h"



link *newLink(int v, int w, link *next) {
	link *new = (link *)malloc(sizeof(link));
	new->vertex = v;
	new->weight = w;
	new->next = next;
	
	return new;
}

graph *initGraph(FILE *input) {
	int i, vertices_num;
	graph *g = (graph *)malloc(sizeof(graph));


	fscanf(input, "%d", &vertices_num);

	g->vertices = vertices_num;
	g->edges = 0;
	g->adj = (link **)malloc(vertices_num * sizeof(link *));
	
	for(i = 0; i < vertices_num; i++) {
		g->adj[i] = NULL;
	}
	
	return g; 
}

void readMatrix(FILE *input, graph *output) {
	int v1, v2, weight, edges_num;
	
	fscanf(input, "%d", &edges_num);
	output->edges = edges_num;
	
	while(fscanf(input, "%d %d %d", &v1, &v2, &weight) == 3) {
		insert(output, v1, v2, weight);
		insert(output, v2, v1, weight);
 	}
	  
	return;
	
}



void insert(graph *output, int valorv1, int valorv2, int weight) {
	link *aux = NULL;
	
	aux = output->adj[valorv1];
	
	if(output->adj[valorv1] == NULL) {
		output->adj[valorv1] = newLink(valorv2, weight, NULL);
		return;
	}
	
	for(aux = output->adj[valorv1]; aux != NULL; aux = aux->next) {
		if(aux->next == NULL) {
			aux->next = newLink(valorv2, weight, NULL);
			return;
		}
	}

	return;
}




char* outputFileExtention(char * name_input){
	char *name_output, *dot;
	
	name_output = (char *)malloc(strlen(name_input) + 2);
	if(name_output == NULL)
		exit(1);
	
	dot = strrchr(name_input, '.');
	
	*dot = '\0';
	
	strcat(name_input, ".ladj");
	strcpy(name_output, name_input);
	
	return name_output;
}


void writeFile(char *oldfile, graph *g) {
	FILE *f;
	char *filename;
	
	filename = outputFileExtention(oldfile);
	
	f = fopen(filename, "w");
	if(f == NULL)
		exit(1);
		
    printOutFile(f, g);
    
	fclose(f);
	free(filename);
	
	return;
}


void printOutFile(FILE *output, graph *g){
	int i;
	link *aux;
	
	fprintf(output, "%d\n", g->vertices);
	
	for(i = 0; i < g->vertices; i++) {
		for(aux = g->adj[i]; aux != NULL; aux = aux->next) {
			fprintf(output, "%d:%d ", aux->vertex, aux->weight);
		}
		fprintf(output, "-1\n");
	}
				
 return;
}
	
void freeEverything(graph *g) {
	int i;
	link *aux, *next;
	
	for(i = 0; i < g->vertices; i++) {
		aux = g->adj[i];
		while(aux != NULL) {
			next = aux->next;
			free(aux);
			aux = next;
		}
	}
	
	free(g->adj);
	free(g);
	
	return;
}
