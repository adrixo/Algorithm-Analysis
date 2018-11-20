#include <stdio.h>
#include <stdlib.h>
#include "../../src/algorithmicSchemes/hanoiTowers.c"

void main(void){

	int **towers;
	int nTowers = 3, nDisks = 5;
	int nMovimientos = 0;

	printf("Enter the number of disks: ");
	scanf("%d", &nDisks);

	towers = instanciateTowers(nTowers,nDisks);
	printTowers(towers,nTowers,nDisks);

	hanoi(nDisks,0,2,1,towers, nTowers, nDisks, &nMovimientos);
	hanoiVerbose(nDisks, 0, 2, 1);

	printf("\n\nResultado final - numero de movimientos: %d\n", nMovimientos);
	printTowers(towers,nTowers,nDisks);

}
