
#include <stdio.h>
#include <stdlib.h>
#include "../../src/algorithmicSchemes/greedyAlgorithm/minimunCoinChange.c"

#define NCOINS 7
int coin_dictionary[NCOINS] = {100,50,20,10,5,2,1};

void coinChange(void);

void main(void)
{
  coinChange();
}


/* Sub Programs*/
void coinChange(void)
{
  int *result;
  int amount, repetitions, i;

  printf("\nCoins in use: [ ");
  for(i=0; i<NCOINS-1; i++)
    printf(" %d, ", coin_dictionary[i]);
  printf("%d ]\nEnter the amount: ", coin_dictionary[NCOINS-1]);
  scanf("%d",&amount);

  result = minimunCoinChange(coin_dictionary, NCOINS, amount, &repetitions);

  printf("\nResult: \n");
  for(i=0; i<NCOINS; i++)
    printf(" %20d$ x%d \n", coin_dictionary[i], result[i]);
  printf("\nAlgorithm repetitions: %d\n\n", repetitions);
}
