#include "binarySearch.h"

int binarySearch(int *array, int length, int value)
{
  int i=0, j=length;
  int k;

  while(i<j)
  {
    k = (i+j)/2;

    if(array[k]<value)
      j = k-1;
    if(array[k]>value)
      i = k+1;
    if(array[k]==value)
      return k;
  }

  return k;
}
