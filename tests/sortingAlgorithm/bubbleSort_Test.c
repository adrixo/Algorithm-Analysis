// Implementing bubbleSort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../../utils/array.h"
#include "../../src/sortingAlgorithm/bubbleSort.h"

#define TESTS 12
#define REPETITIONS 20

void main(void)
{
  clock_t clock_start, clock_end;
  double clock_total;
  int i, j;
  int internalCounter, testSize[TESTS] = { 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000};
  int *array;

  double **timeAverrage;

  timeAverrage = (double **) malloc(TESTS * sizeof(double*)); if(timeAverrage==NULL) printf("timeAverrage: malloc problem\n");
  for(int i = 0; i < TESTS; i++) timeAverrage[i] = (double *) malloc(REPETITIONS * sizeof(double));
  // This array is used to calc the time average of an amount of attemps on the same algorithm operating on an array of specific size
  // But later its used as a matrix to place the info that is going to be presented on a external file

  printf("\nBubble Sort: \n\n");

  for(i=0; i<TESTS; i++)
  {
    for(j=0; j<REPETITIONS; j++) //we want the average of the total clock
    {
      array = createArrayRandomNumbers(testSize[i], testSize[i]);

      clock_start = clock();
      internalCounter = bubbleSort( array, testSize[i]);
      clock_end = clock();

      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;
      timeAverrage[i][j] = clock_total;
      free(array);
    }

    //calc of time average and prepare the matrix
    for(j=1; j<REPETITIONS; j++)
      timeAverrage[i][0] += timeAverrage[i][j];
    timeAverrage[i][0] /= REPETITIONS;

    timeAverrage[i][1] = timeAverrage[i][0]; //time average on the second
    timeAverrage[i][0] = testSize[i];  //Array size on the first
    timeAverrage[i][2] = internalCounter; //number of operations on the third

    //And number that times that an algorithm can be run in 1s (1/timeAverrage)
    timeAverrage[i][4] =  timeAverrage[i][1];
    timeAverrage[i][3] = 0;
    while(timeAverrage[i][4] < 1)
    {
      timeAverrage[i][4] += timeAverrage[i][1];
      //timeAverrage[i][3]++;
    }

    printf("\tArraySize: %d\t\tInternalCounter: %10d\t\tClock: %f\t\tRepetions in 10s: %f\n", testSize[i], internalCounter, timeAverrage[i][0], CLOCKS_PER_SEC);
    createArrayFileFromMatrix(timeAverrage, TESTS, 4, "array size ;clock average ;internal counter ;executions in 1 s\n", "Bubble sort");
  }
}
