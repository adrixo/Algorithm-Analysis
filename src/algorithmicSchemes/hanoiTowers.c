/*Tail recursion example*/
int hanoi(int numberOfDisks, int origin, int destination, int aux)
{
  if( n>0 )
  {
    hanoi(numberOfDisks-1, origin, aux, destination);
    printf("Moving disk %d from %d to %d\n", numberOfDisks, origin, destination);
    hanoi(numberOfDisks-1, aux, destination, origin);
  }
}
