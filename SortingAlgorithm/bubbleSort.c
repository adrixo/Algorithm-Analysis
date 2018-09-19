#include "bubbleSort.h"

void swap(int *x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

int bubbleSort(int *array, int length)
{
  int i, j;
  int c = 0;

  for(i = 0; i < length-1; i++)
  {
    for(j = 0; j < length-i-1; j++)
    {
      if( array[j] < array[j+1])
        swap(&array[j], &array[j+1]);
      c++;
    }
  }
  
  return c;
}
