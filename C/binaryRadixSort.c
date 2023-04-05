#include <stdlib.h>

#include "sorts.h"

static void digitCountingSort(int array[], int length, int digit);


void binaryRadixSort(int array[], int length)
{
	int maxNumber = 0;
	int i;

	// This finds the highest number so it knows how many times to iterate
	for (i = 0; i < length; i++)
		if (array[i] > maxNumber)
			maxNumber = array[i];


	for (i = 0; (1 << i) <= maxNumber; i++)
		digitCountingSort(array, length, i);
}


void digitCountingSort(int array[], int length, int shiftBy)
{
	int valuesTotal[2] = { 0 };
	int *secondaryArray = malloc(length * sizeof(int));
	int i;

	// This counts how many there are of each of the LSDs of the numbers
	for (i = 0; i < length; i++)
		valuesTotal[(array[i] >> shiftBy) % 2]++;

	valuesTotal[1] = valuesTotal[0];
	valuesTotal[0] = 0;

	for (i = 0; i < length; i++) {
		secondaryArray[valuesTotal[(array[i] >> shiftBy) % 2]] = array[i];
		valuesTotal[(array[i] >> shiftBy) % 2]++;
	}

	for (i = 0; i < length; i++)
		array[i] = secondaryArray[i];

	free(secondaryArray);
}
