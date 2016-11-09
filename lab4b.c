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



link *newLink(int v, link *next) {
	link *new = (link *)malloc(sizeof(struct _link));
	new->vertex = v;
	new->next = next;
	
	return new;
}

graph *initGraph(FILE *input) {
	int i, vertices_num;
	graph *g = (graph *)malloc(sizeof(struct graph));


	fscanf(input, "%d", &vertices_num)
	


	g->vertices = vertices_num;
	g->edges = 0;
	g->adj = (link **)malloc(vertices * sizeof(link *));
	
	for(i = 0; i < vertices; i++)
		g->adj[i] = NULL;
	
	return g; 
}

void readMatrix(FILE *input, graph *output) {
	int i, j, v1, v2, weight, vertices_num, edges_num;
	
	
	
	fscanf(input, "%d", &edges_num);
	output->edges = edges_num;
	
	
	
	while(fscanf(input, "%d %d %d", &v1, &v2, weight) == 1) {
	blabla(output,v1,v2, vertices_num,  weight);
	blabla(output,v2,v1, vertices_num,  weight);

 	}
	  
	return;
	
}



void blabla(graph *output, int valorv1,int valorv2, int vertices_num, int weight){
	int i=0;
	link *aux=NULL;
	

		while (output->adj[valorv1][i]!=NULL) i++;
		aux= newLink(vertices_num, aux);
		aux->weight=weight;
		aux->vertices valorv2;
		output->adj[valorv][i]=aux;

	return;
}




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


void writeFile(char *oldfile, graph g) {
	FILE *f;
	char *filename;
	
	filename = outputFileExtention(oldfile);
	
	f = fopen(filename, "w");
	if(f == NULL)
		exit(1);
		
	
    printOutFile(f,g);
    
	fclose(f);
	
	return;
}


void printOutFile(FILE *output, graph g){

	int i=0, j=0;
	fprintf(output, "%d\n",g.vertices);
	link *aux;
	
	for(i=0; i< g.vertices;i++){
		for(aux=g->adj[i][0]; aux!=NULL;aux=aux->next){
			fprintf(output, "%d:%d ",aux->vertices, aux->weight);
	
	
	
	
		}
		fprintf(output, "-1\n ");
	}
				
	
	
 return;
}
	
	
