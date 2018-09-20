
int recursiveFactorial(int n)
{
  if(n == 1)
    return 1;

  return recursiveFactorial(n-1)*n;
}

int iterativeFactorial(int n)
{
  int result = 1;
  while(n > 1)
  {
    result = result * n;
    n--;
  }
  return result;
}

int recursiveFibonacci(int n)
{
  if(n<2)
    return 1;

  return recursiveFibonacci(n-2) + recursiveFibonacci(n-1);
}

int iterativeFibonacci(int n)
{
  int x=0, y=1, aux;
  for(int i=0; i<n; i++)
  {
    aux = x;
    x = x + y;
    y = aux;
  }
  return x
}

int recursivePow(int n, int p)
{
  if(p==1)
    return n;

  return recursivePow(n, p-1) * n;
}

int iterativePow(int n, int p)
{
  int result = 1;
  while(p > 0)
  {
    result *= n;
    p--;
  }
  return result;
}
