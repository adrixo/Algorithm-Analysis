# Sorting Algorithms makefile
CC = gcc
# CFLAGS =

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Miscelanea
summationAlgorithms_Test: tests/studyFunctions/summationAlgorithms_Test.c
	$(CC) -o summationAlgorithms_Test.exe tests/studyFunctions/summationAlgorithms_Test.c

productFunctions_Test: tests/studyFunctions/productFunctions_Test.c
	$(CC) -o productFunctions_Test.exe tests/studyFunctions/productFunctions_Test.c

RecursiveFunctions_Test: tests/studyFunctions/recursiveFunctions_Test.c
	$(CC) -o recursiveFunctions_Test.exe tests/studyFunctions/recursiveFunctions_Test.c
##/Miscelanea


#Search algorithms

#

#Sorting algorithms
bubbleSort_Test: tests/sortingAlgorithm/bubbleSort_Test.c utils/array.o src/sortingAlgorithm/bubbleSort.o
	$(CC) -o bubbleSort_Test.exe tests/sortingAlgorithm/bubbleSort_Test.c utils/array.o src/sortingAlgorithm/sortingAlgorithm/bubbleSort.o


#Algorithmic schemes
greedyAlgorithms_Test: tests/algorithmicSchemes/greedyAlgorithms_Test.c
	$(CC) -o greedyAlgorithms_Test.exe tests/algorithmicSchemes/greedyAlgorithms_Test.c 

#
timeCountingBase: tests/timeCountingBase.c utils/array.o src/XX/XX.o
	$(CC) -o timeCountingBase.exe tests/timeCountingBase.c utils/array.o src/XX/XX.o

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.exe" -type f -delete
	find . -name "*.txt" -type f -delete
