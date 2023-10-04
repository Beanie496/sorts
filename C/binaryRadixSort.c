#include <stdlib.h>
#include <string.h>

#include "sorts.h"
#include "util.h"

static void digitCountingSort(int array[], int length, int digit);


void binaryRadixSort(int array[], int length)
{
	int max = getHighestNumberInArray(array, length);

	for (int i = 0; (1 << i) <= max; i++)
		digitCountingSort(array, length, i);
}


void digitCountingSort(int array[], int length, int shiftBy)
{
	int valuesTotal[2] = { 0 };
	int *secondaryArray = malloc(length * sizeof(int));

	// This counts how many there are of each of the LSDs of the numbers
	for (int i = 0; i < length; i++)
		valuesTotal[(array[i] >> shiftBy) % 2]++;

	for (int i = 0; i < length; i++) {
		secondaryArray[valuesTotal[(array[i] >> shiftBy) % 2]] = array[i];
		valuesTotal[(array[i] >> shiftBy) % 2]--;
	}

	memcpy(array, secondaryArray, sizeof(*array) * length);

	free(secondaryArray);
}
