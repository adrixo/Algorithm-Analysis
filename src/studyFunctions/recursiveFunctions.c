
double recursiveFactorial(double n, double p, int *repetitions) //Int p: unused, just for test implementation
{
  *repetitions += 1;

  if(n <= 1)
    return 1;

  return recursiveFactorial(n-1,p,repetitions)*n;
}

double iterativeFactorial(double n, double p, int *repetitions) //Int p: unused, just for test implementation
{
  double result = 1;
  while(n > 1)
  {
  *repetitions += 1;
    result = result * n;
    n--;
  }
  return result;
}

double recursiveFibonacci(double n, double p, int *repetitions) //Int p: unused, just for test implementation
{
  *repetitions += 1;

  if(n<2)
    return 1;

  return recursiveFibonacci(n-2,p,repetitions) + recursiveFibonacci(n-1,p,repetitions);
}

double iterativeFibonacci(double n, double p, int *repetitions) //Int p: unused, just for test implementation
{
  *repetitions = 0;

  double x=0, y=1, aux;
  for(int i=0; i<n; i++)
  {
    *repetitions += 1;
    aux = x;
    x = x + y;
    y = aux;
  }
  return x;
}

double recursivePow(double n, double p, int *repetitions) //Int p: unused, just for test implementation
{
  *repetitions += 1;

  if(p==1)
    return n;

  return recursivePow(n, p-1, repetitions) * n;
}

double iterativePow(double n, double p, int *repetitions)
{
  *repetitions = 0;

  double result = 1;
  while(p > 0)
  {
    *repetitions += 1;
    result *= n;
    p--;
  }
  return result;
}

int mergeFindMax(int *array, int bot, int top)
{
  int aux1, aux2;

  if(bot == top)
    return (array[bot]);

  aux1 = mergeFindMax(array, bot, (bot+top)/2 );
  aux2 = mergeFindMax(array, ((bot+top)/2)+1, top );

  if (aux1 > aux2)
    return aux1;
  return aux2;

}

int findMountain(int *array, int bot, int top, int nElements)
{
  int k = (bot+top)/2;

  if( (k==1 || array[k-1]<=array[k]) &&
      (k==nElements || array[k+1] <= array[k]) )
      return k;

  if( k>1 && array[k-1]>array[k] )
    return findMountain(array, bot, k-1, nElements);

  return findMountain(array, k+1, top, nElements);

}
