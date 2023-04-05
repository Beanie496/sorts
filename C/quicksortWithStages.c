#include <stdio.h>

#include "sorts.h"

static void partition(int *start, int* end, int *iteration);


void quicksortWithStages(int array[], int length)
{
	int iteration = 1;
	partition(array, array + length - 1, &iteration);
}


void partition(int *start, int* end, int *iteration)
{
	if (start > end - 1)
		return;

	printf("Pass %d: ", (*iteration)++);
	printArray(start, end - start + 1);

	int *pivot = end;
	int *p1 = start;
	int *p2 = p1 - 1;

	// this partitions the array
	while (++p2 < pivot)
		if (*p2 < *pivot)
			swap(p1++, p2);

	swap(p1, pivot);

	partition(start, p1 - 1, iteration);
	partition(p1 + 1, end, iteration);
}
