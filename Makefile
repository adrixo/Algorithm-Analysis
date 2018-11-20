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
sortTest: tests/sortingAlgorithm/sortTest.c
	$(CC) -o sortTest_Test.exe tests/sortingAlgorithm/sortTest.c

bubbleSort_Test: tests/sortingAlgorithm/bubbleSort_Test.c utils/array.o src/sortingAlgorithm/bubbleSort.o
	$(CC) -o bubbleSort_Test.exe tests/sortingAlgorithm/bubbleSort_Test.c utils/array.o src/sortingAlgorithm/bubbleSort.o

selectionSort_Test: tests/sortingAlgorithm/selectionSort_Test.c
	$(CC) -o selectionSort_Test.exe tests/sortingAlgorithm/selectionSort_Test.c

insertionSort_Test: tests/sortingAlgorithm/insertionSort_Test.c
	$(CC) -o insertionSort_Test.exe tests/sortingAlgorithm/insertionSort_Test.c

insertionSortComparation_Test: tests/sortingAlgorithm/insertionSortComparation_Test.c
	$(CC) -o insertionSortComparation_Test.exe tests/sortingAlgorithm/insertionSortComparation_Test.c

quickSort_Test: tests/sortingAlgorithm/quickSort_Test.c
	$(CC) -o quickSort_Test.exe tests/sortingAlgorithm/quickSort_Test.c

mergeSort_Test: tests/sortingAlgorithm/mergeSort_Test.c
	$(CC) -o mergeSort_Test.exe tests/sortingAlgorithm/mergeSort_Test.c

radixSort_Test: tests/sortingAlgorithm/radixSort_Test.c
	$(CC) -o radixSort_Test.exe tests/sortingAlgorithm/radixSort_Test.c

#Algorithmic schemes
greedyAlgorithms_Test: tests/algorithmicSchemes/greedyAlgorithms_Test.c
	$(CC) -o greedyAlgorithms_Test.exe tests/algorithmicSchemes/greedyAlgorithms_Test.c

hanoi_Test: tests/algorithmicSchemes/hanoi_Test.c
	$(CC) -o hanoi_Test.exe tests/algorithmicSchemes/hanoi_Test.c
#

timeCountingBase: tests/timeCountingBase.c utils/array.o src/XX/XX.o
	$(CC) -o timeCountingBase.exe tests/timeCountingBase.c utils/array.o src/XX/XX.o


all: summationAlgorithms_Test productFunctions_Test RecursiveFunctions_Test sortTest bubbleSort_Test insertionSort_Test selectionSort_Test insertionSortComparation_Test greedyAlgorithms_Test

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.exe" -type f -delete
	find . -name "*.txt" -type f -delete
