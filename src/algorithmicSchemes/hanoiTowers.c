/*study a tail recursion example*/
int hanoiVerbose(int numberOfDisks, int origin, int destination, int aux)
{
  if( numberOfDisks>0 )
  {
    hanoiVerbose(numberOfDisks-1, origin, aux, destination);
    printf("Moving disk %d from %d to %d\n", numberOfDisks, origin+1, destination+1);
    hanoiVerbose(numberOfDisks-1, aux, destination, origin);
  }
}

int hanoiDiagram(int numberOfDisks, int origin, int destination, int aux, int position)
{
  if( numberOfDisks>0 )
  {
    hanoiDiagram(numberOfDisks-1, origin, aux, destination, (position-2)/2);
    for(int i=0; i<position; i++) printf("  ");
    printf("(%d, %d, %d, %d)\n\n", numberOfDisks, origin+1, destination+1, aux+1);
    hanoiDiagram(numberOfDisks-1, aux, destination, origin, position*2);
  }
}

int ** instanciateTowers(int length, int numberOfDisks)
{
  int i, j;
  int ** towers;

  towers = (int **) malloc(length * sizeof(double*));
  if(towers==NULL)
    printf("towers: malloc problem\n");

  for(i = 0; i < length; i++)
  {
    towers[i] = (int *) malloc(numberOfDisks * sizeof(int));
    if(i==0)
      for(j = 0; j < numberOfDisks; j++)
        towers[i][j] = numberOfDisks - j;
    else
      for(j = 0; j < numberOfDisks; j++)
        towers[i][j] = 0;
  }
  return towers;
}

void printTowers(int ** towers, int length, int numberOfDisks){
  int i, j;
  for(j = numberOfDisks-1; j >=0 ; j--){
    for(i = 0; i < length; i++){
      if(towers[i][j] == 0)
        printf(" | | ");
      else
        printf(" |%d| ", towers[i][j]);
    }
    printf("\n");
  }
  for(i = 0; i < length; i++)
    printf(" +-+ ");
  printf("\n\n");
}

void moveDisk(int **towers, int origin, int destination)
{
  int i;
  int aux;

  for(i = 0; towers[origin][i] != 0 ||  towers[origin][i] != 1 ; i++){
    if( towers[origin][i] == 1 ){
      aux = towers[origin][i];
      towers[origin][i] = 0;
      break;
    }
    if(towers[origin][i] == 0){
        aux = towers[origin][i-1];
        towers[origin][i-1] = 0;
        break;
    }
  }

  for(i = 0; 1 ; i++){
    if( towers[destination][i] == 0 ){
      towers[destination][i] = aux;
      break;
    }
  }
}

int hanoi(int numberOfDisks, int origin, int destination, int aux, int **towers, int globalNumberOfTowers, int globalNumberOfDisks, int * nMovimientos)
{
  if( numberOfDisks>0 )
  {
    hanoi(numberOfDisks-1, origin, aux, destination, towers, globalNumberOfTowers, globalNumberOfDisks, nMovimientos);

    printf("Moving disk %d from %d to %d\n", numberOfDisks, origin+1, destination+1);
    moveDisk(towers, origin, destination);
    (*nMovimientos)++;
    printTowers(towers, globalNumberOfTowers, globalNumberOfDisks);

    hanoi(numberOfDisks-1, aux, destination, origin, towers, globalNumberOfTowers, globalNumberOfDisks, nMovimientos);
  }
}
