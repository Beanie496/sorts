#include <stdlib.h>

#include "sorts.h"
#include "util.h"

static void digitCountingSort(int array[], int length, int digit);


void decimalRadixSort(int array[], int length)
{
	int maxNumber = 0;
	int i;

	// This finds the highest number so it knows how many times to iterate
	for (i = 0; i < length; i++)
		if (array[i] > maxNumber)
			maxNumber = array[i];


	for (i = 1; i < maxNumber + 1; i *= 10)
		digitCountingSort(array, length, i);
}


void digitCountingSort(int array[], int length, int digit)
{
	int valuesTotal[10] = { 0 };
	int *secondaryArray = malloc(length * sizeof(int));
	int i;

	// This counts how many there are of each of the LSDs of the numbers
	for (i = 0; i < length; i++)
		valuesTotal[(array[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		valuesTotal[i] += valuesTotal[i - 1];

	for (i = 8; i >= 0; i--)
		valuesTotal[i + 1] = valuesTotal[i];
	valuesTotal[0] = 0;

	for (i = 0; i < length; i++) {
		secondaryArray[valuesTotal[(array[i] / digit) % 10]] = array[i];
		valuesTotal[(array[i] / digit) % 10]++;
	}

	for (i = 0; i < length; i++)
		array[i] = secondaryArray[i];
	free(secondaryArray);
}
