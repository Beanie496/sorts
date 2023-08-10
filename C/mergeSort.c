#include <stdlib.h>
#include <string.h>

#include "sorts.h"
#include "util.h"

static void merge(int *array1, int *array2, int length);


void mergeSort(int array[], int length)
{
	if (length == 1)
		return;

	mergeSort(array, length / 2);
	mergeSort(array + length / 2, (length + 1) / 2);

	merge(array, array + length / 2, length);
}


void merge(int *array1, int *array2, int length)
{
	int *secondaryArray = malloc(length * sizeof(int));
	int *mainArray = array1;
	int *array1End = array2 - 1;
	int *array2End = array1 + length - 1;
	int idx = 0;

	while (array1 <= array1End && array2 <= array2End)
		if (*array2 < *array1)
			secondaryArray[idx++] = *array2++;
		else
			secondaryArray[idx++] = *array1++;

	// If the second list's start pointer has gone past its end, that means
	// that it's gone through all its elements. That means that list 1
	// still has elements in it.
	if (array2 > array2End)
		while (array1 <= array1End)
			secondaryArray[idx++] = *array1++;
	// And vice versa.
	else
		while (array2 <= array2End)
			secondaryArray[idx++] = *array2++;

	memcpy(mainArray, secondaryArray, sizeof(*mainArray) * length);

	free(secondaryArray);
}
