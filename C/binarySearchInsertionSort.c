#include <string.h>

#include "sorts.h"
#include "util.h"

 // this inserts the value at value into start, moving all ints forwards by one
static void insert(int *insert, int *value);
static int *binarySearch(int array[], int length, int *value);


void binaryInsertionSort(int array[], int length)
{
	int *searchPtr = array;

	while (++searchPtr - array < length)
		insert(binarySearch(array, searchPtr - array, searchPtr), searchPtr);
}


void insert(int *insert, int *value)
{
	// { X, X, X, v }
	int temp = *value;
	// { -, X, X, X }
	memmove(insert + 1, insert, (value - insert) * sizeof(*value));
	// { v, X, X, X }
	*insert = temp;
}


int *binarySearch(int array[], int length, int *value)
{
	if (length == 0)
		return array;

	if (length == 1)
		// if the value in the array is smaller than the value, it
		// needs to be inserted after
		if (array[0] < *value)
			return array + 1;
		// otherwise, it needs to be inserted before
		else
			return array;

	if (array[length / 2] > *value)
		return binarySearch(&array[0], length / 2, value);
	else if (array[length / 2] == *value)
		return &array[length / 2];
	else
		return binarySearch(&array[length / 2 + 1], (length - 1) / 2, value);
}
