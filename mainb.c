/*
 * mainb.c
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


#include <stdio.h>
#include <stdio.h>
#include "lab4b.h"

int main(int argc, char **argv)
{
	graph *graph2;
	FILE *fp_input;
	
	fp_input = fopen(argv[1], "r");
	
	graph2 = initGraph(fp_input);
	readMatrix(fp_input, graph2);
	writeFile(argv[1], graph2);
	
	return 0;
}

