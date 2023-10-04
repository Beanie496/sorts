#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorts.h"
#include "util.h"

int dosort(int length, int (*sort)(int *array, int length), char *message);


int main(int argc, char *argv[])
{
	// TODO: command-line args

	// 100,000,000
	dosort(100000000, (int (*)(int *, int))binaryRadixSort, "Binary radix sort");

	// 400,000
	dosort(400000, (int (*)(int *, int))binaryInsertionSort, "Binary search insertion sort");

	// 11
	// you can try 12, but do you really want to wait that long?
	// remember bogo sorts are O(n!)
	int iterations = dosort(11, bogoSort, "Bogo sort");
	printf("Iterations: %d\n\n", iterations);

	// 40,000
	dosort(40000, (int (*)(int *, int))bubbleSort, "Bubble sort");

	// 100,000,000
	dosort(100, (int (*)(int *, int))countingSort, "Counting sort");

	// 100,000,000
	dosort(100000000, (int (*)(int *, int))decimalRadixSort, "Decimal radix sort");

	// 10,000,000
	dosort(10000000, (int (*)(int *, int))heapsort, "Heapsort");

	// 100,000,000
	dosort(100000000, (int (*)(int *, int))hexidecimalRadixSort, "Hexidecimal radix sort");

	// 10,000,000
	dosort(10000000, (int (*)(int *, int))mergeSort, "Merge sort");

	// 1,000,000
	dosort(1000000, (int (*)(int *, int))quicksort, "Quicksort");

	// 100
	dosort(100, (int (*)(int *, int))quicksortWithStages, "Quicksort with stages");

	// 250
	dosort(250, (int (*)(int *, int))slowsort, "Slowsort");

	// 2,000
	dosort(2000, (int (*)(int *, int))stoogeSort, "Stooge sort");

	// 100,000,000
	dosort(400000000, (int (*)(int *, int))threadedMergeSort, "Threaded merge sort");

	return 0;
}


int dosort(int length, int (*sort)(int *array, int length), char *message)
{
	int *array = initArray(length, 1000);
	printArray(array, length);
	printf("\nLength: %d\n", length);
	printf("%s:\n", message);

	// this is likely going to be garbage, but it's used once
	int ret = sort(array, length);

	printf("Sorted.\n");
	printArray(array, length);
	printf("\n\n");
	free(array);

	return ret;
}
