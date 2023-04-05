#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorts.h"


int main(int argc, char *argv[])
{
	// TODO: command-line args
	int *array;
	int length;


	// 100,000,000
	length = 100000000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Binary radix sort:\n");
	binaryRadixSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);


	// 100,000
	length = 100000;
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
	length = 10000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Bubble sort:\n");
	bubbleSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 100,000,000
	length = 10000000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Counting sort:\n");
	countingSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 100,000,000
	length = 100000000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Decimal radix sort:\n");
	decimalRadixSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 10,000,000
	length = 10000000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Heapsort:\n");
	heapsort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 100,000,000
	length = 100000000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Hexidecimal radix sort:\n");
	hexidecimalRadixSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 10,000,000
	length = 10000000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Merge sort:\n");
	mergeSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 1,000,000
	length = 1000000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Quicksort:\n");
	quicksort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 100
	length = 100;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Quicksort with stages:\n");
	quicksortWithStages(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 250
	length = 250;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Slowsort:\n");
	slowsort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 2000
	length = 2000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Stooge sort:\n");
	stoogeSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	// 10,000,000
	length = 100000000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Threaded merge sort:\n");
	threadedMergeSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	printf("\n");
	free(array);

	return 0;
}
