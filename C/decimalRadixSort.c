#include <stdlib.h>
#include <string.h>

#include "sorts.h"
#include "util.h"

static void digitCountingSort(int array[], int length, int digit);


void decimalRadixSort(int array[], int length)
{
	int max = getHighestNumberInArray(array, length);

	for (int i = 1; i < max + 1; i *= 10)
		digitCountingSort(array, length, i);
}


void digitCountingSort(int array[], int length, int digit)
{
	int valuesTotal[10] = { 0 };
	int *secondaryArray = malloc(length * sizeof(int));

	// This counts how many there are of each of the LSDs of the numbers
	for (int i = 0; i < length; i++)
		valuesTotal[(array[i] / digit) % 10]++;

	for (int i = 1; i < 10; i++)
		valuesTotal[i] += valuesTotal[i - 1];

	for (int i = 0; i < length; i++) {
		secondaryArray[valuesTotal[(array[i] / digit) % 10]] = array[i];
		valuesTotal[(array[i] / digit) % 10]--;
	}

	memcpy(array, secondaryArray, sizeof(*array) * length);

	free(secondaryArray);
}
