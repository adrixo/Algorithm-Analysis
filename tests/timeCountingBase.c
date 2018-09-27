// Implementing an algorithm

/*
  #include "../src/.."

  macros

  main()

/*Declarations
    double matrix to calc time average
    double matrix to calc repetitions average
    double matrix to save the data to be represented
      DATA:
        ARRAY SIZE;
        time average;
        repetitions average;
        nº of repetitions in 1s;

/*Algorithm benchmark
    For(number of test)
      For(number of repetitions for each test)
        algorithm()

      saving the DATA

/* Presentation of the DATA
    presentation on screen,
    saving to a file
 */

//Number of repetitions can be provided by sort/search funciton return or reference parameter

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../utils/array.h"
#include "../src/sortingAlgorithm/bubbleSort.h"

#define TESTS 12
#define REPETITIONS 20
#define PRESENTATIONMATRIXFIELDS 4

int testSize[TESTS] = { 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000};

void main(void)
{
  clock_t clock_start, clock_end;
  double clock_total;
  int i, j;
  int internalCounter;
  int *array;

/*Declarations*/
  double **timesCollection;
  timesCollection = (double **) malloc(TESTS * sizeof(double*)); if(timesCollection==NULL) printf("timesCollection: malloc problem\n");
  for( i = 0; i < TESTS; i++) timesCollection[i] = (double *) malloc(REPETITIONS * sizeof(double));
  // This array is used to calc the time average of an amount of attemps on the same algorithm operating on an array of specific size

  int **repetitionsCollection;int
  repetitionsCollection = (int **) malloc(TESTS * sizeof(int*)); if(repetitionsCollection==NULL) printf("repetitionsCollection: malloc problem\n");
  for( i = 0; i < TESTS; i++) repetitionsCollection[i] = (int *) malloc(REPETITIONS * sizeof(int));

  double **presentationMatrix;
  presentationMatrix = (double **) malloc(TESTS * sizeof(double*)); if(presentationMatrix==NULL) printf("presentationMatrix: malloc problem\n");
  for( i = 0; i < TESTS; i++){
    presentationMatrix[i] = (double *) malloc(PRESENTATIONMATRIXFIELDS * sizeof(double));
    for(j=0; j<PRESENTATIONMATRIXFIELDS; j++)
      presentationMatrix[i][j] = 1;
  }

/*Algorithm*/
  printf("\n Algorithm name: \n\n");

  for(i=0; i<TESTS; i++)
  {
    for(j=0; j<REPETITIONS; j++) //we want the average of the total clock
    {
      array = createArrayRandomNumbers(testSize[i], testSize[i]);

      clock_start = clock();
      internalCounter = bubbleSort( array, testSize[i]);
      clock_end = clock();

      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;
      timesCollection[i][j] = clock_total;
      repetitionsCollection[i][j] = internalCounter;
      free(array);
    }

/*Saving the data on the presentation Matrix*/

    presentationMatrix[i][0] = testSize[i];  //Array size on the first
    for(j=1; j<REPETITIONS; j++)
    {
      presentationMatrix[i][1] += timesCollection[i][j];
      presentationMatrix[i][2] += repetitionsCollection[i][j];
    }
    presentationMatrix[i][1] /= REPETITIONS;
    presentationMatrix[i][2] /= REPETITIONS;
    presentationMatrix[i][3] =  1/presentationMatrix[i][1];    //And number that times that an algorithm can be run in 1s (1/timesCollection)


    printf("\tArraySize: %10.0f\t\tClock: %10f\t\tInternalCounter: %10.0f\t\tRepetions in 1s: %.2f\n", presentationMatrix[i][0], presentationMatrix[i][1], presentationMatrix[i][2], presentationMatrix[i][3]);
    createArrayFileFromMatrix(presentationMatrix, TESTS, PRESENTATIONMATRIXFIELDS, "array size ;clock average ;internal counter ;executions in 1 s\n", "ALGORITHM");
  }
}
