#include <stdlib.h>
#include <string.h>

#include "sorts.h"
#include "util.h"

static void digitCountingSort(int array[], int length, int digit);


void hexidecimalRadixSort(int array[], int length)
{
	int max = getHighestNumberInArray(array, length);

	for (int i = 0; 1 << i <= max; i += 4)
		digitCountingSort(array, length, i);
}


void digitCountingSort(int array[], int length, int digit)
{
	int valuesTotal[16] = { 0 };
	int* secondaryArray = malloc(length * sizeof(int));

	// This counts how many there are of each of the LSDs of the numbers
	for (int i = 0; i < length; i++)
		valuesTotal[(array[i] >> digit) % 16]++;

	for (int i = 1; i < 16; i++)
		valuesTotal[i] += valuesTotal[i - 1];

	memmove(&valuesTotal[1], &valuesTotal[0], sizeof(*valuesTotal) * 15);
	valuesTotal[0] = 0;

	for (int i = 0; i < length; i++) {
		secondaryArray[valuesTotal[(array[i] >> digit) % 16]] = array[i];
		valuesTotal[(array[i] >> digit) % 16]++;
	}

	memcpy(array, secondaryArray, sizeof(*array) * length);

	free(secondaryArray);
}
