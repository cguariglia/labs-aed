/******************************************************************************
 *
 * File Name: pal.h
 *	      (c) 2009 AED
 * Author:    AED Team
 * Revision:  v2.1
 *
 * NAME
 *	lab10 - Hash table
 *
 * SYNOPSIS
 *	#include <stdlib.h>
 *	#include <stdio.h>
 *	#include <string.h>
 *	#include <malloc.h>
 *
 * DESCRIPTION
 *
 * DIAGNOSTICS tested
 *
 *****************************************************************************/

#define PESO 117

typedef struct _No {
  char *palavra;
  int ocorrencias;
  struct _No *prox;
} No;


typedef struct _Info {
  int m;                        /* dimension of the vector */
  int numPalavras;              /* number of different words  */
  int *num_pal;                 /* hash table hits count */
  int num_comp;                 /* number of comparisons */
  int max_size;			/* size of the biggest list */
  int empty;			/* number of empty lists */
} Info;


typedef No *Hash;               /* typedef for hash table */


char *LePalavra(FILE *);
FILE *AbreFicheiro(char *, char *);
No *AlocaNo(char *);
void AcrescentaNo(No *, No *);
Hash *AlocaTabela(int);
int Disperse(char *, int);
void InsereNaTabela(Hash *, Info *, char *);
void PreencheTabelaPalavras(Hash *, Info *, char *);
void EscreveFicheiro(Hash *, char *, int);
void MostraDistribuicao(Hash *, Info *);
void LibertarTabela(int, Hash *);
void LibertarNo(No *);
