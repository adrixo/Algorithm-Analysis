#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array.h"

int * createArrayRandomNumbers(int n, int max)
{
  srand((unsigned) time(NULL));

  int * array, i;
  array = (int *) malloc (n*sizeof(int));
  if(array == NULL)
  {
    printf("createArray: error in malloc\n");
    return NULL;
  }

  for(i = 0; i < n; i++)
    array[i] = rand() % max;

  return array;
}

void printArray(int * array, int length, char *name)
{
  printf("%s: [ ", name);
  for(int i = 0; i < length-1; i++)
  {
    printf(" %d,", array[i]);
  }
  printf(" %d ]\n", array[length-1]);
}
