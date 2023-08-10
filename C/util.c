#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "util.h"


int *initArray(int length, int range)
{
	int *array = malloc(length * sizeof(int));

	srand(time(0));

	// initialising array with random numbers from 0 to 'range'
	for (int i = 0; i < length; i++)
		array[i] = rand() % (range + 1);

	return array;
}


void printArray(int *array, int length)
{
	printf("%d", array[0]);
	for (int i = 1; i < length; i++)
		printf(", %d", array[i]);
}


void swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int getHighestNumberInArray(int array[], int length)
{
	int max = 0;
	for (int i = 0; i < length; i++)
		if (array[i] > max)
			max = array[i];
	return max;
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
