#include "sorts.h"

static void swap (int* startPointer, int* endPointer);


void stoogeSort(int array[], int length)
{
	if (length == 2) {
		if (array[0] > array[1])
			swap(array, array + 1);
		return;
	}

	stoogeSort(array, 2 * (length + 1) / 3);
	stoogeSort(array + length / 3, 2 * (length + 1) /3);
	stoogeSort(array, 2 * (length + 1) / 3);
}


void swap (int* startPointer, int* endPointer)
{
	int temp = *startPointer;
	*startPointer = *endPointer;
	*endPointer = temp;
}
