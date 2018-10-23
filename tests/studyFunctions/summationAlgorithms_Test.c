#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../src/studyFunctions/summationAlgorithms.c"

char *names[] = {
  "twoSummatory",
  "twoSummatory2",
  "threeSummatoriesExpN",
  "secondSummatoryTiedToFirst",
  "thirdSummatoryTiedToSecond",
  "summatoriestiedRecursively",
  "dividedBy2",
  "dividedBy3",
  "repetitionsInsideSummatory_Product",
  "repetitionsInsideSummatory_Add"
};

int (*algorithms[]) (int ) = {
  &twoSummatory,
  &twoSummatory2,
  &threeSummatoriesExpN,
  &secondSummatoryTiedToFirst,
  &thirdSummatoryTiedToSecond,
  &summatoriestiedRecursively,
  &dividedBy2,
  &dividedBy3,
  &repetitionsInsideSummatory_Product,
  &repetitionsInsideSummatory_Add
};

void main(void)
{
  clock_t clock_start, clock_end;
  double clock_total;
  int i, j, repetitions;
  int n, N[5] = { 50, 100, 200, 400, 800};
  int Nexponential[5] = {3, 6, 12, 24, 48};

  for(i=0; i<10; i++){
    printf("\nFunction: %s\n",names[i]);
    for(j=0; j<5; j++)
    {
      if(i!=2) //If the 3rd is so slow we can ignore it o(n⁶) - n=50 takes 30 sec
        n = N[j];
      else
        n = Nexponential[j];

      clock_start = clock();

      repetitions = (*algorithms[i])(n);

      clock_end = clock();
      clock_total = (clock_end - clock_start) / (double) CLOCKS_PER_SEC;

      //if(i!=2)
        printf("%d: %d\tn: %-10dclock: %f\tRepetitions in 1s: %.2f\n", i+1, n, repetitions, clock_total, 1/clock_total);
      //else
      //  printf("The thirds algorithm takes too much time, check code.\n");
    }
    printf("\n");
  }
}
