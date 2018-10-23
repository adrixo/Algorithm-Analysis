#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../src/studyFunctions/productFunctions.c"

#define TESTS 5
#define FUNCTIONS 4

char *names[] = {
  "classicProduct",
  "russianProduct",
  "divideAndConquerProduct",
  "iterativeProduct"
};

int(*algorithms[])(int, int, int *) = {
  &classicProduct,
  &russianProduct,
  &divideAndConquerProduct,
  &iterativeProduct
};

int MR[TESTS] = {12, 123, 1234, 12345, 123456};
int MO[TESTS] = {24, 456, 5678, 67891, 789123};

void main(void)
{
  clock_t clock_start, clock_end;
  double clock_total;
  int i, j, repetitions, result;
  int mr, mo;

  for(i=0; i<FUNCTIONS; i++){
    printf("\nFunction: %s\n",names[i]);
    for(j=0; j<TESTS; j++)
    {
      mr = MR[j];
      mo = MO[j];

      clock_start = clock();

      result = (*algorithms[i])(mr, mo, &repetitions);

      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;

      printf("%d: %10d*%-10d = %-10d\tn: %-10dclock: %f\tRepetitions in 1s: %.2f\n", i+1, mr, mo, result, repetitions, clock_total, 1/clock_total);
    }
    printf("\n");
  }
}
