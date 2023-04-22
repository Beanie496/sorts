#include <stdlib.h>

#include "sorts.h"
#include "util.h"


void mergeSort(int array[], int length)
{
	if (length == 1)
		return;

	int halfOfLength = length >> 1;

	mergeSort(array, halfOfLength);
	mergeSort(array + halfOfLength, length + 1 >> 1);

	merge(array, array + halfOfLength, length);
}


void merge(int *array1, int *array2, int length)
{
	int *secondaryArray = malloc(length * sizeof(int));

	int *mainArray = array1;
	int *array1End = array2 - 1;
	int *array2End = array1 + length - 1;

	int i = 0;


	while (array1 <= array1End && array2 <= array2End) {
		if (*array2 < *array1)
			secondaryArray[i] = *array2++;
		else
			secondaryArray[i] = *array1++;
		i++;
	}

	// If the second list's start pointer has gone past its end, that means that it's gone through all its elements. That means that list 1 still has elements in it.
	if (array2 > array2End)
		while (array1 <= array1End)
			secondaryArray[i++] = *array1++;
	// And vice versa.
	else
		while (array2 <= array2End)
			secondaryArray[i++] = *array2++;

	for (i = 0; i < length; i++)
		mainArray[i] = secondaryArray[i];


	free(secondaryArray);
}
