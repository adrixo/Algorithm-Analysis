#ifndef __X_NARYSEARCH_H
#define __X_NARYSEARCH_H

int ternarySearch(int *array, int length, int value, int *repetitions);
int recursiveTernarySearch(int *array, int bot, int top, int value, int * repetitions);
int x_narySearch(int *array, int length, int value, int x, int *repetitions);
int recursiveX_narySearch(int *array, int bot, int top, int value, int x, int * repetitions);

#endif
