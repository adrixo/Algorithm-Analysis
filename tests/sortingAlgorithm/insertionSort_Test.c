#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../src/sortingAlgorithm/insertionSort.c"
#include "../../utils/array.c"

#define TESTS 5
#define REPETITIONS 10

void main(void)
{
  clock_t global_clock = clock();

  clock_t clock_start, clock_end;
  double clock_total;
  int i, j;
  int testSize[TESTS] = { 1000, 5000, 10000, 20000, 50000};
  int *arrayRandomDirect;
  int *arrayRandomBinary;
  int *sortedArray;
  int *reversedArrayDirect;
  int *reversedArraybinary;

  int internalCounterDirect, internalCounterBinary;

  double **timeAverrageDirect;
  double **timeAverrageBinary;

  timeAverrageDirect = (double **) malloc(TESTS * sizeof(double*)); if(timeAverrageDirect==NULL) printf("timeAverrage: malloc problem\n");
  for(int i = 0; i < TESTS; i++) timeAverrageDirect[i] = (double *) malloc(REPETITIONS * sizeof(double));

  timeAverrageBinary = (double **) malloc(TESTS * sizeof(double*)); if(timeAverrageBinary==NULL) printf("timeAverrage: malloc problem\n");
  for(int i = 0; i < TESTS; i++) timeAverrageBinary[i] = (double *) malloc(REPETITIONS * sizeof(double));

  printf("\n Insertion Sorting: Direct (1.) vs binary (2.): \n\n");

/* Middle case */
  printf("\n[Middle case] - array with random numbers:\n");
  for(i=0; i<TESTS; i++)
  {
    for(j=0; j<REPETITIONS; j++)
    {
      arrayRandomDirect = createArrayRandomNumbers(testSize[i], testSize[i]);
      arrayRandomBinary = duplicateArray(arrayRandomDirect, testSize[i]);

      clock_start = clock();
      internalCounterDirect = insertionSort( arrayRandomDirect, testSize[i]);
      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;
      timeAverrageDirect[i][j] = clock_total;

      clock_start = clock();
      internalCounterBinary = binaryInsertionSort( arrayRandomBinary, testSize[i]);
      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;
      timeAverrageBinary[i][j] = clock_total;

      free(arrayRandomDirect);
      free(arrayRandomBinary);
    }

    for(j=1; j<REPETITIONS; j++){
      timeAverrageDirect[i][0] += timeAverrageDirect[i][j];
      timeAverrageBinary[i][0] += timeAverrageBinary[i][j];
    }
    timeAverrageDirect[i][0] /= REPETITIONS;
    timeAverrageBinary[i][0] /= REPETITIONS;

    printf("1.Size: %d\t\tInternalCounter: %10d\t\tClock: %f\t\tRepetions in 1s: %f\n", testSize[i], internalCounterDirect, timeAverrageDirect[i][0], 1/timeAverrageDirect[i][0] );
    printf("2.Size: %d\t\tInternalCounter: %10d\t\tClock: %f\t\tRepetions in 1s: %f\n\n", testSize[i], internalCounterBinary, timeAverrageBinary[i][0], 1/timeAverrageBinary[i][0]);
  }

/* Best case */
  printf("\n[Best case] - Sorted array:\n");
  for(i=0; i<TESTS; i++)
  {
    for(j=0; j<REPETITIONS; j++)
    {

      sortedArray = createSortedArray(testSize[i]);

      clock_start = clock();
      internalCounterDirect = insertionSort( sortedArray, testSize[i]);
      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;
      timeAverrageDirect[i][j] = clock_total;

      clock_start = clock();
      internalCounterBinary = binaryInsertionSort( sortedArray, testSize[i]);
      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;
      timeAverrageBinary[i][j] = clock_total;

      free(sortedArray);
    }

    for(j=1; j<REPETITIONS; j++){
      timeAverrageDirect[i][0] += timeAverrageDirect[i][j];
      timeAverrageBinary[i][0] += timeAverrageBinary[i][j];
    }
    timeAverrageDirect[i][0] /= REPETITIONS;
    timeAverrageBinary[i][0] /= REPETITIONS;

    printf("1.Size: %d\t\tInternalCounter: %10d\t\tClock: %f\t\tRepetions in 1s: %f\n", testSize[i], internalCounterDirect, timeAverrageDirect[i][0], 1/timeAverrageDirect[i][0]);
    printf("2.Size: %d\t\tInternalCounter: %10d\t\tClock: %f\t\tRepetions in 1s: %f\n\n", testSize[i], internalCounterBinary, timeAverrageBinary[i][0], 1/timeAverrageBinary[i][0]);
  }

/* worst case */
  int repetitionsWorstCase = REPETITIONS;
  repetitionsWorstCase = 2;
  printf("\n[Best case] - Array sorted backwards:\n");
  for(i=0; i<TESTS; i++)
  {
    for(j=0; j<repetitionsWorstCase; j++)
    {

      reversedArrayDirect = createReversedArray(testSize[i]);
      reversedArraybinary = createReversedArray(testSize[i]);

      clock_start = clock();
      internalCounterDirect = insertionSort( reversedArrayDirect, testSize[i]);
      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;
      timeAverrageDirect[i][j] = clock_total;

      clock_start = clock();
      internalCounterBinary = binaryInsertionSort( reversedArraybinary, testSize[i]);
      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;
      timeAverrageBinary[i][j] = clock_total;

      free(reversedArrayDirect);
      free(reversedArraybinary);
    }

    //Calculamos las medias de los tiempos
    for(j=1; j<repetitionsWorstCase; j++){
      timeAverrageDirect[i][0] += timeAverrageDirect[i][j];
      timeAverrageBinary[i][0] += timeAverrageBinary[i][j];
    }
    timeAverrageDirect[i][0] /= repetitionsWorstCase;
    timeAverrageBinary[i][0] /= repetitionsWorstCase;

    printf("1.Size: %d\t\tInternalCounter: %10d\t\tClock: %f\t\tRepetions in 1s: %f\n", testSize[i], internalCounterDirect, timeAverrageDirect[i][0], 1/timeAverrageDirect[i][0]);
    printf("2.Size: %d\t\tInternalCounter: %10d\t\tClock: %f\t\tRepetions in 1s: %f\n\n", testSize[i], internalCounterBinary, timeAverrageBinary[i][0], 1/timeAverrageBinary[i][0]);
  }

  clock_end = clock();
  clock_total = (clock_end - global_clock) / (double) CLOCKS_PER_SEC;
  printf("Execution time: %f\n", clock_total);
}
