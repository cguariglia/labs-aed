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

typedef struct _link link;

struct _link {
	int vertex;
	_link *next;
}

struct graph{
	int edges;
	int vertices;
	link **adj;
};

link *newLink(int v, link *next) {
	link *new = (link *)malloc(sizeof(struct _link));
	new->vertex = v;
	new->next = next;
	
	return new;
}

graph *initGraph(int vertices) {
	int i;
	graph *g = (graph *)malloc(sizeof(struct graph));
	
	g->vertices = vertices;
	g->edges = 0;
	g->adj = (link **)malloc(vertices * sizeof(link *));
	
	for(i = 0; i < vertices; i++)
		g->adj[i] = NULL;
	
	return g; 
}

void readMatrix(FILE *input, graph *output) {
	int i, j, v1, v2, weight, vertices_num, edges_num;
	
	fscanf(input, %d, &vertices_num)
	output->vertices = vertices_num;
	
	fscanf(input, %d, &edges_num);
	output->edges = edges_num;
	
	while(fscanf(input, "%d %d %d", &v1, &v2, weight) == 1) {
		
	}
	  
	return;
	
}
