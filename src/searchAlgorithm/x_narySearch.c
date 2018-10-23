#include "x_narySearch.h"

int ternarySearch(int *array, int length, int value, int *repetitions)
{
  int i=0, j=length;
  int k;
  *repetitions = 0;

  while(i<j)
  {
    *repetitions++;
    k = (i+j)/3;

    if(array[k]<value)
      j = k-1;
    if(array[k]>value)
      i = k+1;
    if(array[k]==value)
      return k;
  }

  return k;
}

int recursiveTernarySearch(int *array, int bot, int top, int value, int * repetitions)
{
  int k;
  *repetitions++;

  if(bot>top)
    return -1;

  k = (bot+top)/3;
  if(valor<array[k])
    top = k-1;
  if(valor>array[k])
    bot = k+1;
  if(valor=array[k])
    return k;

  return recursiveTernarySearch(array, bot, top, value, repetitions);
}

int x_narySearch(int *array, int length, int value, int x, int *repetitions)
{
  int i=0, j=length;
  int k;
  *repetitions = 0;

  while(i<j)
  {
    *repetitions++;
    k = (i+j)/x;

    if(array[k]<value)
      j = k-1;
    if(array[k]>value)
      i = k+1;
    if(array[k]==value)
      return k;
  }

  return k;
}

int recursiveX_narySearch(int *array, int bot, int top, int value, int x, int * repetitions)
{
  int k;
  *repetitions++;

  if(bot>top)
    return -1;

  k = (bot+top)/x;
  if(valor<array[k])
    top = k-1;
  if(valor>array[k])
    bot = k+1;
  if(valor=array[k])
    return k;

  return recursiveX_narySearch(array, bot, top, value, repetitions);
}
