#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
  clock_t clock_start, clock_end;
  double clock_total;

  clock_start = clock();
  clock_end = clock();

  clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;

  printf("%d:\t%d\tn: %d\t\tclock: %f\n", i+1, n, repetitions, clock_total);

}
