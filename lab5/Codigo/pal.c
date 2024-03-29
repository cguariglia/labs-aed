/******************************************************************************
 *
 * File Name: pal.c
 *	      (c) 2009 AED
 * Author:    AED Team
 * Revision:  v2.1 ACR
 *
 * NAME
 *	lab10 - Hash Table auxiliary functions
 *
 * SYNOPSIS
 *	#include <stdlib.h>
 *	#include <string.h>
 *	#include <stdio.h>
 *	#include <malloc.h>
 *
 * DESCRIPTION
 *
 * DIAGNOSTICS tested
 *
 *****************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "pal.h"


/******************************************************************************
 * LePalavra()
 *
 * Arguments: f - file pointer for file to read from
 * Returns: pointer to word read
 * Side-Effects: none
 *
 * Description: read a word from the given file
 *
 *****************************************************************************/

char *LePalavra(FILE * f)
{
  static char palavra[100];     /* it is assumed that the words found in files
                                   are limited in length. note that the variable
                                   is defined as "static". */

  if (fscanf(f, "%s", palavra) == 1)
    return palavra;
  else
    return NULL;
}


/******************************************************************************
 * AbreFicheiro()
 *
 * Arguments: nome - name of file to open
 *            mode - mode used when opening
 * Returns: file pointer
 * Side-Effects: none
 *
 * Description: opens file with given mode ("r", "w", etc)
 *
 *****************************************************************************/

FILE *AbreFicheiro(char *nome, char *mode)
{
  FILE *f;

  f = fopen(nome, mode);
  if (f == NULL) {
    fprintf(stderr, "*** Invalid Filename %s.", nome);
    exit(1);
  }

  return f;
}


/******************************************************************************
 * AlocaNo()
 *
 * Arguments: palavra - pointer to word string
 * Returns: pointer to node
 * Side-Effects: new node is allocated
 *
 * Description: new node is allocated to hold word information
 *
 *****************************************************************************/

No *AlocaNo(char *palavra)
{
  No *novo;

  novo = (No *) malloc(1 * sizeof(No));
  novo->palavra = malloc((strlen(palavra) + 1) * sizeof(char));
  strcpy(novo->palavra, palavra);
  novo->ocorrencias = 1;
  novo->prox = NULL;

  return novo;
}


/******************************************************************************
 * AcrescentaNo()
 *
 * Arguments: no1, no2 - node pointers
 * Returns: (void)
 * Side-Effects: node list is changed
 *
 * Description: node is added to list
 *
 *****************************************************************************/

void AcrescentaNo(No * no1, No * no2)
{

  /* node no1 is added after no2 */
  no1->prox = no2->prox;
  no2->prox = no1;

  return;
}

/******************************************************************************
 * AlocaTabela()
 *
 * Arguments: m - size of table to allocate
 * Returns: (void)
 * Side-Effects: new table is created
 *
 * Description: creates and initializes new table of node pointers
 *
 *****************************************************************************/

Hash *AlocaTabela(int m)
{
  int i;
  Hash *tabela;

  tabela = (No **) malloc(m * sizeof(No *));
  for (i = 0; i < m; i++)
    tabela[i] = NULL;

  return tabela;
}


/******************************************************************************
 * Disperse()
 *
 * Arguments: palavra - pointer to word string
 * Returns: index into hash table
 * Side-Effects: none
 *
 * Description: computes hash (index into hash table) for given word
 *
 *****************************************************************************/

int Disperse(char *palavra, int m)
{
  unsigned int i, pp;
  unsigned int p = PESO;
  unsigned int h = 0;

  int n = strlen(palavra);
  for (i = 0; i < (unsigned int)n; i++) {
    /* to avoid problem with acented characters, etc */
    pp = ((unsigned int)palavra[i]) % 512;
    h = (pp * p + h) % m;
  }

  return h;
}

/******************************************************************************
 * InsereNaTabela()
 *
 * Arguments: t - hash table
 *            h - variables structure
 *			   palavra - pointer to word string
 * Returns: (void)
 * Side-Effects: word is added to hash table
 *
 * Description: inserts new word into hash table at the appropriate index
 *
 *****************************************************************************/

void InsereNaTabela(Hash * t, Info * h, char *palavra)
{
  No *x = NULL, *z = NULL;
  int i = 0;

  i = Disperse(palavra, h->m);
  x = t[i];
  if (t[i] != NULL) {
    for (x = t[i]; x != NULL; x = x->prox) {

      h->num_comp++;
      if (strcmp(x->palavra, palavra) == 0) {
        x->ocorrencias = 1 + x->ocorrencias;
        break;
      }
      if (x->prox == NULL) {
        h->num_pal[i]++;
        h->numPalavras++;
        z = AlocaNo(palavra);
        AcrescentaNo(z, x);
        break;
      }
    }
  }
  else if (t[i] == NULL) {
    h->numPalavras++;
    t[i] = AlocaNo(palavra);
    h->num_pal[i]++;

  }
  return;
}


/******************************************************************************
 * PreencheTabelaPalavras()
 *
 * Arguments: t - hash table
 *            h - variables structure
 *			   ficheiro - name of file to read from
 * Returns: (void)
 * Side-Effects: file is opened and read; table is filled
 *
 * Description: given file is opened and read, word for word; each word is in
 *              turn inserted into table
 *
 *****************************************************************************/

void PreencheTabelaPalavras(Hash * t, Info * h, char *ficheiro)
{
  FILE *f;
  char *palavra;

  f = AbreFicheiro(ficheiro, "r");
  while ((palavra = LePalavra(f)) != NULL) {
    InsereNaTabela(t, h, palavra);
  }
  fclose(f);

  return;
}


/******************************************************************************
 * EscreveFicheiro()
 *
 * Arguments:	t - hash table
 *				ficheiro - name of file to write to
 *				m - hash table size
 * Returns: (void)
 * Side-Effects: output file is created
 *
 * Description: writes required information to output file
 *
 *****************************************************************************/

void EscreveFicheiro(Hash * tabela, char *ficheiro, int m)
{
  FILE *f;
  char *nome;
  int i = 0;
  No *aux;

  nome = (char *)malloc(strlen(ficheiro) + strlen(".palavras") + 1);
  strcpy(nome, ficheiro);
  strcat(nome, ".palavras");
  f = AbreFicheiro(nome, "w");

  for (i = 0; i < m; i++) {
    aux = tabela[i];

    if (aux != NULL) {
      fprintf(f, "tabela[%3d] ================  \n", i);
      do {
        fprintf(f, "   %d: %s\n", aux->ocorrencias, aux->palavra);
        aux = aux->prox;
      } while (aux != NULL);
    }
    fprintf(f, "\n");
  }
  fclose(f);
  free(nome);
}


/******************************************************************************
 * MostraDistribuicao()
 *
 * Arguments: t - hash table
 *            h - variables structure
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: shows distribution of words in hash table
 *
 *****************************************************************************/

void MostraDistribuicao(Hash * tabela, Info * h)
{
  int i, j, numPal, empty_lists = 0, biggest_list = 0;
  No *aux;

  printf("\n\tDistribution of words in the hash table\n");

  /*******************************************************************
   * Insert code in this function to determine
   * the biggest list size and number of empty lists
   * and update h according
   *******************************************************************/

for (i = 0; i < h->m; i++) {

    aux = tabela[i];
    numPal = 0;

    while (aux != NULL) {
      aux = aux->prox;
      numPal++;
    }

    if(numPal > biggest_list)
        biggest_list = numPal;
    else if(numPal == 0)
        empty_lists++;

    printf("[%2d] Np=  %d ", i, h->num_pal[i]);
    for (j = 0; j < numPal; j++)
      printf("#");

    printf("\n");
    
    }

    h->max_size = biggest_list;
    h->empty = empty_lists;

  return;
}


/******************************************************************************
 * LibertarTabela()
 *
 * Arguments: m - size of table to free
 * Returns: (void)
 * Side-Effects: hash table is freed
 *
 * Description: frees memory occupied by hash table and attached nodes
 *
 *****************************************************************************/

void LibertarTabela(int m, Hash * t)
{
  No *no1, *no2;
  int i = 0;

  for (i = 0; i < m; i++) {
    for (; t[i] != NULL; t[i] = no2) {
      no2 = t[i]->prox;
      no1 = t[i];
      LibertarNo(no1);
    }
  }

  return;
}


/******************************************************************************
 * LibertarNo()
 *
 * Arguments: no - node structure to be freed
 * Returns: (void)
 * Side-Effects: node memory is freed
 *
 * Description: frees node memory
 *
 *****************************************************************************/

void LibertarNo(No * no)
{

  free(no->palavra);
  free(no);

  return;
}
