#include <stdio.h>

#include "sorts.h"


void printArray(int *array, int length)
{
	printf("%d", array[0]);
	for (int i = 1; i < length; i++)
		printf(", %d", array[i]);
}
