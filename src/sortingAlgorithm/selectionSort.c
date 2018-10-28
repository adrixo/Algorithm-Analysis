
int selectionSort(int *array, int length)
{
  int i, j, repetitions = 0;
  int aux;
  int selection;

  for(i = 0; i < length-1; i++)
  {
    selection = i;

    for(j = i+1; j<length; j++)
    {
        if(array[j] < array[selection])
          selection = j;
        repetitions++;
    }

    if(selection != i)
    {
      aux = array[selection];
      array[selection] = array[i];
      array[i] = aux;
    }
  }

  return repetitions;
}


int selectionSortSecondVersion(int *array, int length)
{
  int i, j, repetitions = 0;
  int selectionIndex, selectionValue;
  int aux;
  
  for(i = 1; i < length; i++)
  {
    selectionIndex = i;
    selectionValue = array[i];

    for(j = i-1; j>=0 && array[j] > aux; j--)
    {
        array[j+1] = array[j];
        repetitions++;
    }

    array[j+1] = aux;
  }

  return repetitions;
}
