
int classicProduct(int mo, int mr)
{
  int result = 0;

  while()
  {
    add = ciffer * mo;
    result = result + pow(10,) * add;
  }

  return result;
}

int russianProduct(int mo, int mr)
{
  int result = 0;
  while( mo != 0 )
  {
    if( mo%2 != 0 )
      result = result + mr;
    mo /= 2;
    mr = mr + 2;
  }
  return result;
}

int divideAndConquerProduct(int mo, int mr)
{
  int n =
}

int iterativeProduct(int mo, int mr)
{
  int result = 0;
  int i = mr;
  while( i >= 1)
  {
    result = result + mo;
    i = i - 1;
  }
  return result;
}
