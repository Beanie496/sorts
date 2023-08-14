#include <stdlib.h>
#include <string.h>

#include "sorts.h"
#include "util.h"


void countingSort(int array[], int length)
{
	int *secondaryArray = malloc(length * sizeof(int));
	int max = getHighestNumberInArray(array, length);
	// '+ 1' because it's 0 to max, not 1
	int countingList[max + 1];

	// can't initialise variable-sized object with 0's
	memset(countingList, 0, sizeof(*countingList) * (max + 1));

	// count occurances of each number
	for (int i = 0; i < length; i++)
		countingList[array[i]]++;

	// make each entry the cumulative sum of all the previous entries
	for (int i = 1; i < max + 1; i++)
		countingList[i] += countingList[i - 1];

	for (int i = 0; i < length; i++) {
		// get the right index for the number and insert it
		secondaryArray[countingList[array[i]] - 1] = array[i];
		// increment the index, as the next identical number needs to
		// be stored in the next index
		countingList[array[i]]--;
	}

	memcpy(array, secondaryArray, sizeof(*array) * length);

	free(secondaryArray);
}
