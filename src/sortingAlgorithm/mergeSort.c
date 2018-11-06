//merge sort

int merge(int *array, int bot, int mid, int top)
{
  int c=0;
  int i, j, k;
  int dimA = mid - bot + 1;
  int dimB =  top - mid;

  int A[dimA], B[dimB];

  for (i = 0; i < dimA; i++){
    A[i] = array[bot + i];
    c++;
  }
  for (j = 0; j < dimB; j++){
    B[j] = array[mid + 1+ j];
    c++;
  }

  i = 0;
  j = 0;
  k = bot;
  while (i < dimA && j < dimB){
    if (A[i] <= B[j]){
      array[k] = A[i];
      i++;
    }
    else {
      array[k] = B[j];
      j++;
    }
    k++;
    c++;
  }
  while (i < dimA){
    array[k] = A[i];
    i++;
    k++;
    c++;
  }

  while (j < dimB){
    array[k] = B[j];
    j++;
    k++;
    c++;
  }
  return c;
}


int mergeSort(int * array, int bot, int top){
  int c = 0;
  if(bot<top){
    c += mergeSort(array, bot, (bot+top)/2);
    c += mergeSort(array, (bot+top)/2 + 1, top);
    c += merge(array, bot, (bot+top)/2, top);
  }
  return c;
}
