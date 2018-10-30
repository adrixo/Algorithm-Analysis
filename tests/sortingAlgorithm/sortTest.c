// Implementing bubbleSort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../../src/sortingAlgorithm/quickSort.c"
#include "../../utils/array.c"

#define ARRAYSIZE 100

void main(void)
{
  clock_t clock_start, clock_end;
  double clock_total;
  int internalCounter;
  int *array;

  printf("\n Sort test: \n\n");

  array = createArrayRandomNumbers( ARRAYSIZE, ARRAYSIZE);

  printArray(array, ARRAYSIZE, "Sort test, 1.");
  clock_start = clock();
  internalCounter = quickSortImproved( array,0, ARRAYSIZE-1);    clock_end = clock();
  clock_end = clock();

  clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;
  printArray(array, ARRAYSIZE, "Sort test, 2.");
  printf("Repetitions: %d\n", internalCounter);

  free(array);

}
