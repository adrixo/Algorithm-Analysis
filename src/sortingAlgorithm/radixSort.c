int getMax(int *array, int length, int *c){
  int max = array[0];
  for (int i = 1; i < length; i++){
    (*c)++;
    if (array[i] > max)
      max = array[i];
  }
  return max;
}

int countSort(int array[], int length, int exp)
{
  int c = 0;
  int output[length];
  int i, count[10] = {0};

  for (i = 0; i < length; i++){
    count[ (array[i]/exp)%10 ]++;
    c++;
  }

  for (i = 1; i < 10; i++){
    count[i] += count[i - 1];
    c++;
  }

  for (i = length - 1; i >= 0; i--){
    output[count[ (array[i]/exp)%10 ] - 1] = array[i];
    count[ (array[i]/exp)%10 ]--;
    c++;
  }

  for (i = 0; i < length; i++){
    array[i] = output[i];
    c++;
  }
  return c;
}

int radixSort(int *array, int length)
{
  int c = 1;
  int m = getMax(array, length, &c);

  for (int exp = 1; m/exp > 0; exp *= 10)
    c += countSort(array, length, exp);

  return c;
}
