//Quicksort

void swap(int *x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

int place(int *array, int bot, int top, int * c){
  int pivot = bot, i;
  int pivotValue = array[bot];
  for(i=bot+1; i<top; i++){
    (*c)++;
    if(array[i]<pivotValue){
      pivot++;
      swap(&array[pivot], &array[i]);
    }
  }
  swap(&array[bot], &array[pivot]);
  return pivot;
}

int quickSort(int *array, int bot, int top){

  int c = 0;
  if(bot<top){
    int pivot = place(array, bot, top, &c);
    return c +
        quickSort(array, bot, pivot-1) +
        quickSort(array, pivot + 1, top);
  }

  return c;
}


int quickSortImproved(int *array, int bot, int top){
  int i=bot, j=top;
  int pivot = (bot+top)/2;
  int pivotValue = array[pivot];
  int c = 0;

  do {
    while(array[i]<pivotValue){
      i++;
      c++;
    }

    while(array[j]>pivotValue){
      j--;
      c++;
    }

    if(i<=j){
      swap(&array[i],&array[j]);
      i++;
      j--;
      c++;
    }
  } while(i>=j);

  if(bot<j){
    return c + quickSortImproved(array, bot, j);
  }

  if(bot>i){
    return c + quickSortImproved(array, i, top);
  }
  return c;
}
