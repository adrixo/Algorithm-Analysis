#include "sequentialSearch.h"

int sequentialSearch(int *array, int length, int value)
{
  int i;

  for(i=0; i<length; i++)
    if(array[i]==value)
      return i;

  return -1;
}
