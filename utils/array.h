#ifndef __ARRAY_H
#define __ARRAY_H

typedef struct algorithm_data {
  int testSize;
  double timeAverrage;
  double execPerSecond;
  int internalCounter;
} info;

typedef info * algorithmAttemp;

int * createArrayRandomNumbers(int n, int max);
int * duplicateArray(int *array, int size);
void printArray(int * array, int length, char *name);
void createArrayFileFromMatrix(double ** array, int x, int y, char * topbar, char * fileName);

#endif
