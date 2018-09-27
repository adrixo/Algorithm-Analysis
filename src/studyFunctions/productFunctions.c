
int powRecursive(int x, int y)
{
  if(y==1)
    return x;
  if(y>1)
    return powRecursive(x, y-1) * x;

  return 1;
}

int classicProduct(int mo, int mr, int * repetitions)
{
  int result = 0;

  *repetitions = 0;

  int add;
  int aux = mr;
  int position = -1;
  int digit;

  while(aux != 0)
  {
    (*repetitions)++;

    position++;
    digit = aux%10;
    aux /= 10;

    add = digit * mo;
    result += powRecursive(10,position) * add;
  }

  return result;
}

int russianProduct(int mo, int mr, int * repetitions)
{
  *repetitions = 0;
  int result = 0;

  while( mo != 0 )
  {
    (*repetitions)++;

    if( mo%2 != 0 )
      result = result + mr;

    mo /= 2;
    mr *= 2;
  }
  return result;
}

/*int divideAndConquerProduct(int mo, int mr, int * repetitions)
{
  int n;


}*/

int iterativeProduct(int mo, int mr, int * repetitions)
{
  int result = 0;
  int i = mr;
  *repetitions = 0;

  while( i >= 1)
  {
    (*repetitions)++;
    result = result + mo;
    i = i - 1;
  }
  return result;
}
