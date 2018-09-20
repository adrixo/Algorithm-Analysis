# Sorting Algorithms makefile
CC = gcc
# CFLAGS =

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


summationAlgorithms_Test: tests/summationAlgorithms_Test.c
	$(CC) -o summationAlgorithms_Test.exe tests/summationAlgorithms_Test.c

bubbleSort_Test: tests/exampleBubble_Test.c utils/array.o sortingAlgorithm/bubbleSort.o
	$(CC) -o bubble_Test.exe tests/exampleBubble_Test.c utils/array.o sortingAlgorithm/bubbleSort.o

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.exe" -type f -delete
