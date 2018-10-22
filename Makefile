# Sorting Algorithms makefile
CC = gcc
# CFLAGS =

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Miscelanea
summationAlgorithms_Test: tests/summationAlgorithms_Test.c
	$(CC) -o summationAlgorithms_Test.exe tests/summationAlgorithms_Test.c

productFunctions_Test: tests/productFunctions_Test.c
	$(CC) -o productFunctions_Test.exe tests/productFunctions_Test.c

RecursiveFunctions_Test: tests/recursiveFunctions_Test.c
	$(CC) -o recursiveFunctions_Test.exe tests/recursiveFunctions_Test.c
##/Miscelanea


#Sort algorithms
bubbleSort_Test: tests/bubbleSort_Test.c utils/array.o src/sortingAlgorithm/bubbleSort.o
	$(CC) -o bubbleSort_Test.exe tests/bubbleSort_Test.c utils/array.o src/sortingAlgorithm/bubbleSort.o

#Search algorithms

#
timeCountingBase: tests/timeCountingBase.c utils/array.o src/XX/XX.o
	$(CC) -o timeCountingBase.exe tests/timeCountingBase.c utils/array.o src/XX/XX.o

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.exe" -type f -delete
	find . -name "*.txt" -type f -delete
