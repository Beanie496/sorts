#include <stdio.h>
#include <stdlib.h>
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
