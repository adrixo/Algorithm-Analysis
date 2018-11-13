
int insertionSort(int *array, int length)
{
  int i, j, repetitions = 0;
  int aux;

  for(i = 1; i < length; i++)
  {
    aux = array[i];

    for(j = i-1; j>=0 && array[j] > aux; j--)
    {
        array[j+1] = array[j];
        repetitions++;
    }

    array[j+1] = aux;
  }

  return repetitions;
}

int binaryInsertionSort(int * array, int length)
{
  int i, j;
  int base, tope;
  int m, aInsertar;
  int contador = 0;

  for(i = 1; i < length; i++)
  {
    aInsertar = array[i];
    if(aInsertar<array[i-1])
    {
      base = 0;
      tope = i-1;
      while(base <= tope)
      {
        contador++;
        m = (base+tope) / 2;
        if(aInsertar <= array[m])
          tope = m-1;
        else
          base = m + 1;
      }
      j = i - 1;
      while(j >= base)
      {
        contador++;
        array[j+1] = array[j];
        j = j - 1;
      }
      array[base] = aInsertar;
    }
    else
      contador++;
  }

  return contador;
}
