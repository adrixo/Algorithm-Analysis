#include "sequentialSearch.h"

int sequentialSearch(int *array, int length, int value, int repetitions)
{
  int i;

  *repetitions = 0;

  for(i=0; i<length; i++)
  {
    *repetitions++;
    if(array[i]==value)
      return i;
  }
  return -1;
}
