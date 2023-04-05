#include <stdlib.h>

#include "sorts.h"

static void digitCountingSort(int array[], int length, int digit);


void hexidecimalRadixSort(int array[], int length)
{
	int maxNumber = 0;
	int i;
	
	// This finds the highest number so it knows how many times to iterate
	for (i = 0; i < length; i++)
		if (array[i] > maxNumber)
			maxNumber = array[i];

	for (i = 0; 1 << (i * 4) <= maxNumber; i++)
		digitCountingSort(array, length, i);
}


void digitCountingSort(int array[], int length, int digit)
{
	int valuesTotal[16] = { 0 };
	int* secondaryArray = malloc(length * sizeof(int));
	int i;

	// This counts how many there are of each of the LSDs of the numbers
	for (i = 0; i < length; i++)
		valuesTotal[(array[i] >> (digit * 4)) % 16]++;

	for (i = 1; i < 16; i++)
		valuesTotal[i] += valuesTotal[i - 1];

	for (i = 15; i > 0; i--)
		valuesTotal[i] = valuesTotal[i - 1];
	valuesTotal[0] = 0;

	for (i = 0; i < length; i++) {
		secondaryArray[valuesTotal[(array[i] >> (digit * 4)) % 16]] = array[i];
		valuesTotal[(array[i] >> (digit * 4)) % 16]++;
	}

	for (i = 0; i < length; i++)
		array[i] = secondaryArray[i];
	free(secondaryArray);
}
