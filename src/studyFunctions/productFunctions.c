
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

int maxDigits(int mo, int mr)
{
    int i=0, j=0;

    while(mo!=0 && mr!=0)
    {
      if(mo!=0){
        mo = mo/10;
        i++;
      }

      if(mr!=0){
        mr = mr/10;
        j++;
      }
    }

    if(i>j)
      return i;
    return j;
}

int divideAndConquerProduct(int mo, int mr, int * repetitions)
{
  *repetitions += 1;
  int n;
  int s,w,x,v,y;

  n = maxDigits(mo,mr);

  if(n <= 3)
    return mo * mr;

  s = n / 2;

  w = mo / powRecursive(10, s);
  x = mo % powRecursive(10, s);
  v = mr / powRecursive(10, s);
  y = mr % powRecursive(10, s);

  return divideAndConquerProduct(w,v,repetitions)*powRecursive(10, 2*s) +
        divideAndConquerProduct(w,y,repetitions)*powRecursive(10, s) +
        divideAndConquerProduct(x,v,repetitions)*powRecursive(10, s) +
        divideAndConquerProduct(x,y,repetitions);
}

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
