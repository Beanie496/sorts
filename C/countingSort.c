#include <stdlib.h>

#include "sorts.h"
#include "util.h"


void countingSort(int array[], int length)
{
	int *secondaryArray = malloc(length * sizeof(int));
	int maxNumber = 0;
	int i;

	// This finds the highest number so it knows how long to make the counting list
	for (i = 0; i < length; i++)
		if (array[i] > maxNumber)
			maxNumber = array[i];
	int countingList[maxNumber + 1]; // '+ 1' because it's 0 to maxNumber, not 1

	for (i = 0; i < maxNumber + 1; i++)
		countingList[i] = 0;

	// count occurances of each number
	for (i = 0; i < length; i++)
		countingList[array[i]]++;

	// make each entry the cumalative sum of all the previous entries
	// TODO: sp?
	for (i = 1; i < maxNumber + 1; i++)
		countingList[i] += countingList[i - 1];

	// shift each number along in order to get the starting index of each number
	for (i = maxNumber; i >= 0; i--)
		countingList[i + 1] = countingList[i];
	countingList[0] = 0;

	for (i = 0; i < length; i++) {
		// get the right index for the number and insert it
		secondaryArray[countingList[array[i]]] = array[i];
		// increment the index, as the next identical number needs to be stored
		// in the next index
		countingList[array[i]]++;
	}

	for (i = 0; i < length; i++)
		array[i] = secondaryArray[i];

	free(secondaryArray);
}
