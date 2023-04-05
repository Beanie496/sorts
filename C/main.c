#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorts.h"


int main(int argc, char *argv[])
{
	int *array;
	int length;


	// 100,000,000
	length = 1000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Binary radix sort:\n");
	binaryRadixSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);


	// 100,000
	length = 1000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Binary search insertion sort:\n");
	binaryInsertionSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 11
	// you can try 12, but do you really want to wait that long?
	// remember bogo sorts are O(n!)
	length = 11;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Bogo sort:\n");
	int iterations = bogoSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("Iterations: %d\n", iterations);
	printf("\n");
	free(array);

	// 10,000
	length = 1000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Bubble sort:\n");
	bubbleSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 100,000,000
	length = 1000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Counting sort:\n");
	countingSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	return 0;
}
