/*
 * lab4a.h
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
#include "lab4a.h"

int main(int argc, char **argv) {
	
	FILE *fp_input;
	graph grafo1;
	
	
	fp_input = fopen(argv[1], "r");
	
	
	
	readMatrix(fp_input, &grafo1);

	printDensity(grafo1);
	printMaxDegree(grafo1, grafo1.vertices);
	
	writeFile(argv[1], grafo1);
	
	fclose(fp_input);
	freeMatrix(&grafo1);
	
	
	return 0;
}

