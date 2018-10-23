#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../src/studyFunctions/recursiveFunctions.c"

#define TESTS 5
#define FUNCTIONS 6

char *names[] = {
  "recursiveFactorial",
  "iterativeFactorial",
  "recursiveFibonacci",
  "iterativeFibonacci",
  "recursivePow",
  "iterativePow"
};

double(*algorithms[])(double, double, int*) = {
  &recursiveFactorial,
  &iterativeFactorial,
  &recursiveFibonacci,
  &iterativeFibonacci,
  &recursivePow,
  &iterativePow
};

int linear[TESTS] = {20, 25, 30, 35, 40};
int exponent[TESTS] = {16, 32, 48, 64, 80};


void main(void)
{
  clock_t clock_start, clock_end;
  double clock_total;
  int i, j, repetitions=0;
  double result;
  int e, l;

  for(i=0; i<FUNCTIONS; i++){
    printf("\nFunction: %s\n",names[i]);
    for(j=0; j<TESTS; j++)
    {
      repetitions = 0;
      l = linear[j];
      e = exponent[j];

      clock_start = clock();

      if(i<4)
        result = (*algorithms[i])(l, 0, &repetitions);
      else
        result = (*algorithms[i])(2, e, &repetitions);

      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;


      if(i<4)
        printf("%d: n:%10d = %-50.f\trepetitions: %-10dclock: %f\tRepetitions in 1s: %.2f\n", i+1, l, result, repetitions, clock_total, 1/clock_total);
      else
        printf("%d: 2^%10d = %-25.f\trepetitions: %-10dclock: %f\tRepetitions in 1s: %.2f\n", i+1, e, result, repetitions, clock_total, 1/clock_total);
    }
    printf("\n");
  }
}
