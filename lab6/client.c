/******************************************************************************
 * File Name: client.c
 *	      (c) 2010 AED
 * Author:    AED Team
 * Revision:  v2.3 ACR
 * NAME
 *     Lab11 - Heap (Acervo)
 * SYNOPSIS
 *		#include <stdlib.h>
 *		#include <stdio.h>
 *		#include <malloc.h>
 * DESCRIPTION Exemple of client using  heap for storing a set of Integers
 * DIAGNOSTICS tested
 *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>


#include "heap.h"

/* This is just an example; change as required for your application */
#define HEAPSIZE 24


/******************************************************************************
 * PrintNumero()
 *
 * Arguments: hi - pointer to number to be printed, masked as an item
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: Print function with abstract type to be passed as argument;
 *              Prints a number
 *
 *****************************************************************************/

void PrintNum(Item hi)
{
  int num;

  num = *((int *)hi);
  printf("%3d", num);

  return;
}


/******************************************************************************
 * LessNumero()
 *
 * Arguments: a, b - 2 Items to be compared
 * Returns: Integer with the results of the comparison
 * Side-Effects: none
 *
 * Description: Comparison function with abstract type to be passed as argument;
 *              Function is specific for "int" variables
 *
 *****************************************************************************/

int LessNum(Item a, Item b)
{
  int aa, bb;

  aa = *((int *)a);
  bb = *((int *)b);

  return (aa < bb);
}


/******************************************************************************
 * InsertNum()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the insert option
 *
 *****************************************************************************/

void InsertNum(Heap * h)
{
  int *num;
  int i, status;

  printf("Number: ");
  status = scanf("%d", &i);
  if (status == 1) {
    num = (int *)malloc(sizeof(int));
    *num = i;
    if (Insert(h, (Item) num) == 0)
      free(num);
    printf("\nFinal Heap\n");
    PrintHeap(h);
  }
  
  free(num);

  return;
}

/******************************************************************************
 * DirectInsertNum()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the insert option
 *
 *****************************************************************************/

void DirectInsertNum(Heap * h)
{
  int *num;
  int i, status;

  printf("Number: ");
  status = scanf("%d", &i);
  if (status == 1) {
    num = (int *)malloc(sizeof(int));
    *num = i;
    if (Direct_Insert(h, (Item) num) == 0)
      free(num);
    printf("\nFinal Heap\n");
    PrintHeap(h);
  }

  return;
}

/******************************************************************************
 * ModifyNum()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the modify option
 *
 *****************************************************************************/

void ModifyNum(Heap * h)
{
  int indice;
  int *novovalor = (int *)malloc(sizeof(int));

  printf("Index of the element to change: ");
  scanf("%d", &indice);
  printf("New value: ");
  scanf("%d", novovalor);
  Modify(h, indice, (Item) novovalor);
  PrintHeap(h);

  return;
}


/******************************************************************************
 * RemoveMaxNum()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the removemax option
 *
 *****************************************************************************/

void RemoveMaxNum(Heap * h)
{
  RemoveMax(h);
  PrintHeap(h);

  return;
}

/******************************************************************************
 * HeapSortOption()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the heapsort option
 *
 *****************************************************************************/

void HeapSortOption(Heap * h)
{
  HeapSort(h);
  PrintHeap(h);

  return;
}

/******************************************************************************
 * VerifyHeapOption()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the verify heap option
 *
 *****************************************************************************/

void VerifyHeapOption(Heap * h)
{
  if (PrintHeap(h) != 0) {
    if (VerifyHeap(h))
      printf("*************** It is an heap\n");
    else
      printf("*************** It is not an heap\n");
  }
  return;
}

/******************************************************************************
 * HeapifyOption()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the heapify option
 *
 *****************************************************************************/

void HeapifyOption(Heap * h)
{
  Heapify(h);
  PrintHeap(h);

  return;
}

/******************************************************************************
 * Example()
 *
 * Arguments: none
 * Returns: void
 * Side-Effects: none
 *
 * Description: Example heap of size HEAPSIZE, automatic insert from 0 to 11
 *
 *****************************************************************************/

void Example(Heap * h)
{
  int *num;
  int i, n = 12;

  for (i = 0; i < n; i++) {
    num = (int *)malloc(sizeof(int));
    *num = i;
    if (Insert(h, (Item) num) == 0)
      free(num);
  }
  printf("\nFinal Heap\n");
  PrintHeap(h);

  return;                       /*h */
}

/******************************************************************************
 * Help()
 *
 * Arguments: none
 * Returns: void
 * Side-Effects: none
 *
 * Description: Print menu help
 *
 *****************************************************************************/

void Help()
{
  printf
      ("----------------------------------------------------------------------------------------\n");
  printf
      ("insert:        i - insert a number in the heap ensuring the heap condition\n");
  printf
      ("modify:        m - modify an heap element and restores the heap condition\n");
  printf
      ("removemax:     r - remove the first element of the heap and restores the heap condition\n");
  printf
      ("direct insert: d - insert a number in the heap without ensuring the heap condition\n");
  printf("verify:        v - verify if it is an heap\n");
  printf("print:         p - print the heap\n");
  printf("heapify:       f - restore the heap condition\n");
  printf("sort:          s - sort the heap\n");
  printf("example:       e - heap example with 16 numbers\n");
  printf("clean:         c - clean the heap (removes all elements)\n");
  printf("help:          h - show this help\n");
  printf("quit:          q - quit\n");
  printf
      ("----------------------------------------------------------------------------------------\n");

  return;
}

/******************************************************************************
 * PrintOptions()
 *
 * Arguments: none
 * Returns: void
 * Side-Effects: none
 *
 * Description: Print interface, provides Heap operation options
 *
 *****************************************************************************/

void PrintOptions()
{
  printf("----------------\n    OPTIONS\n----------------\n");
  printf("insert:        i\n");
  printf("modify:        m\n");
  printf("removemax:     r\n");
  printf("direct insert: d\n");
  printf("verify:        v\n");
  printf("print:         p\n");
  printf("heapify:       f\n");
  printf("sort:          s\n");
  printf("example:       e\n");
  printf("clean:         c\n");
  printf("help:          h\n");
  printf("quit:          q\n");

  return;
}


/******************************************************************************
 * main()
 *
 * Arguments: argc - number of comand line arguments
 *            argc - array of pointers to command line arguments
 * Returns: success or error
 * Side-Effects: none
 *
 * Description: Main interface, allow the choice of available operations
 *				insert, modify, removemax, sort and exit
 *
 *****************************************************************************/

int main(int argc, char **argv)
{
  char command[2];
  Heap *h;

  /* HEAPSIZE defined at the top of this file */
  h = NewHeap(HEAPSIZE, LessNum, PrintNum);

  do {
    PrintOptions();
    printf("Heap> ");
    scanf("%s", command);
    switch (command[0]) {
    case 'i':
      InsertNum(h);
      break;
    case 'm':
      ModifyNum(h);
      break;
    case 'r':
      RemoveMaxNum(h);
      break;
    case 's':
      HeapSortOption(h);
      break;
    case 'e':
      Example(h);
      break;
    case 'p':
      PrintHeap(h);
      break;
    case 'd':
      DirectInsertNum(h);
      break;
    case 'v':
      VerifyHeapOption(h);
      break;
    case ('f'):
      HeapifyOption(h);
      break;
    case ('c'):
      CleanHeap(h);
      break;
    case 'h':
      Help();
      break;
    case 'q':
      FreeHeap(h);
      return 0;
    default:
      printf("\nInvalid option \"%s\"; please insert a valid option\n\n",
             command);
    }
  }
  while (1);
    
    if(h != NULL)
        CleanHeap(h);

  return 0;
}
