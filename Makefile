# Sorting Algorithms makefile
CC = gcc
# CFLAGS =

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


bubbleSort: test.o Utils/array.o SortingAlgorithm/bubbleSort.o
	$(CC) -o bubble.exe test.o Utils/array.o SortingAlgorithm/bubbleSort.o

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.exe" -type f -delete
