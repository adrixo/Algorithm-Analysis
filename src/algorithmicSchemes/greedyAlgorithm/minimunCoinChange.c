
/*
 * Function:  minimunCoinChange
 * --------------------
 * Finds the minimun minimum number of coins which add up to a given amount of money
 *
 *  coin_dictionary: array with coin values - [2$, 1$, 50cts, 20cts, ...]
 *  cd_elements: elements of coin dictionary
 *  Amount: amount to breakdown
 *
 *  returns: the minimun minimum number of coins which add up to a given amount of money
 *           as an int array with matches with the
 *           returns null on error
 */
int * minimunCoinChange(int *coin_dictionary, int elements, int amount, int *repetitions)
{
  int i;
  *repetitions = 0;

  if(coin_dictionary[elements-1] > amount)
    return NULL;

  int * coins = (int *) calloc ( elements, sizeof(int));


  for(i=0; i<elements; i++)
    while(amount >= coin_dictionary[i])
    {
      amount = amount - coin_dictionary[i];
      coins[i]++;
      *repetitions += 1;
    }

  return coins;
}
