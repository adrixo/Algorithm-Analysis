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

int * duplicateArray(int *array, int size)
{
  int *secondArray, i;
  secondArray = (int *) malloc (size*sizeof(int));
  if(secondArray == NULL)
  {
    printf("createArray: error in malloc\n");
    return NULL;
  }

  for(i = 0; i < size; i++)
    secondArray[i] = array[i];

  return secondArray;
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

//The second field has 5 decimals, for the clock
void createArrayFileFromMatrix(double ** array, int x, int y, char * topbar, char * fileName)
{
  FILE *f;
  int i, j, type;
  char fileNameWithExtension[256];

  sprintf(fileNameWithExtension, "%s.txt", fileName);
  f = fopen(fileNameWithExtension, "w+");
  fprintf(f,topbar);

  for(i=0; i<x; i++)
  {
    for(j=0;j<(y-1);j++)
    {
      if(j==1 || j==3)
        fprintf(f, "%f; ", array[i][j]);
      else
        fprintf(f, "%.0f; ", array[i][j]);
    }
    if(j==1)
      fprintf(f, "%f \n", array[i][y-1]);
    else
      fprintf(f, "%.2f; \n", array[i][y-1]);
  }
  fclose(f);
}
