#ifndef __ARRAY_H
#define __ARRAY_H

int * createArrayRandomNumbers(int n, int max);
int * duplicateArray(int *array, int size);
void printArray(int * array, int length, char *name);
void createArrayFile(double ** array, int x, int y, char * topbar, char * fileName);

#endif
