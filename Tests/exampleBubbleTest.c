// Implementing bubbleSort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
  clock_t clock_start, clock_end;
  double clock_total;
  int i, j, repetitions;
  int n, N[5] = { 50, 100, 200, 400, 800};

  for(i=0; i<10; i++){
    printf("\nFunction: %s\n",names[i]);
    for(j=0; j<5; j++)
    {
      n = N[j];
      clock_start = clock();

      if(i!=2) //If the 3rd is so slow we can ignore it o(n⁶) - n=50 takes 30 sec
        repetitions = (*algorithms[i])(n);

      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;

      if(i!=2)
        printf("%d:\t%d\tn: %d\t\tclock: %f\n", i+1, n, repetitions, clock_total);
      else
        printf("The thirds algorithm takes too much time, check code.\n");
    }
    printf("\n");
  }
}
