
int twoSummatory(int n)
{
  int i, j, c;
  c = 1;
  for(i=1; i < n; i++)
    for(j=1; j < n; j++)
      c++;
  return c;
}

int twoSummatory2(int n)
{
  int i, j, k, c;
  c = 1;

  for(i=1; i < n; i++)
    for(j=1; j < n; j++)
      for(k=0; k < 2; k++)
        c++;
  return c;
}

int threeSummatoriesExpN(int n)
{
  int i, j, k, c;
  c = 1;
  for(i=1; i < n; i++)
    for(j=1; j < n*n; j++)
      for(k=1; k < n*n*n; k++)
        c++;
  return c;
}

int secondSummatoryTiedToFirst(int n)
{
  int i, j, c;
  c = 1;
  for(i=1; i < n; i++)
    for(j=1; j < i; j++)
      c++;
  return c;
}

int thirdSummatoryTiedToSecond(int n)
{
  int i, j, k, c;
  c = 1;
  for(i=1; i < n; i++)
    for(j=1; j < n; j++)
      for(k=1; k < j; k++)
        c++;
  return c;
}

int summatoriestiedRecursively(int n)
{
  int i, j, k, c;
  c = 1;
  for(i=1; i < n; i++)
    for(j=1; j < i; j++)
      for(k=1; k < j; k++)
        c++;
  return c;
}

int dividedBy2(int n)
{
  int  j, x;
  x = 0;
  for(j=n; j >= 1; j = j/2)
        x++;
  return x;
}

int dividedBy3(int n)
{
  int  j, x;
  x = 0;
  for(j=n; j >= 1; j = j/3)
        x++;
  return x;
}

int repetitionsInsideSummatory_Product(int n)
{
  int  j, i, x;
  x = 0;
  for(i=1; i <= n; i++)
  {
    j = 1;
    while( j <= i )
    {
      x++;
      j = j*2;
    }
  }
  return x;
}

int repetitionsInsideSummatory_Add(int n)
{
  int  j, i, x;
  x = 0;
  for(i=1; i <= n; i++)
  {
    j = 1;
    while( j <= i )
    {
      x++;
      j = j+2;
    }
  }
  return x;
}
