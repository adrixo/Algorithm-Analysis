#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array.h"

/*aleatorio
aleatorio sin repetidos
orden ascendente
orden descendente
aleatorio sin repeascendente
aleatorio sinrepe ascendente */

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

int * createSortedArrayRandomNumbers(int n, int max)
{
  int * array = createArrayRandomNumbers(n, max);

  void swap(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
  }

  void bubbleSort(int *array, int length){
    for(int i = 0; i < length-1; i++)
      for(int j = 0; j < length-i-1; j++)
        if( array[j] > array[j+1])
          swap(&array[j], &array[j+1]);
  }

  bubbleSort(array, n);

  return array;
}

void reverseArray(int *array, int length)
{
  int aux;
  for(int i = 0; i<length/2; i++)
  {
    aux = array[i];
    array[i] = array[length-i-1];
    array[length-i-1] = aux;
  }
}

int * createSortedArray(int n)
{

  int * array, i;
  array = (int *) malloc (n*sizeof(int));
  if(array == NULL)
  {
    printf("createArray: error in malloc\n");
    return NULL;
  }

  for(i = 0; i < n; i++)
    array[i] = i;

  return array;
}

int * createReversedArray(int n)
{

  int * array, i;
  array = (int *) malloc (n*sizeof(int));
  if(array == NULL)
  {
    printf("createArray: error in malloc\n");
    return NULL;
  }

  for(i = n-1; i >= 0; i--)
    array[n-1-i] = i;

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

  sprintf(fileNameWithExtension, "results/%s.txt", fileName);
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
