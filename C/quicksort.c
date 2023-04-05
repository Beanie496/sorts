#include "sorts.h"

static void swap(int *start, int* end);
static void partition(int *start, int* end);


void quicksort(int array[], int length)
{
	partition(array, array + length - 1);
}


void partition(int *start, int* end)
{
	if (start >= end)
		return;

	int *pivot = end;
	int *p1 = start;
	int *p2 = p1 - 1;

	// this partitions the array
	while (++p2 < pivot)
		if (*p2 < *pivot)
			swap(p1++, p2);
	
	swap(p1, pivot);

	partition(start, p1 - 1);
	partition(p1 + 1, end);
}


void swap(int *start, int* end)
{
	int temp = *end;
	*end = *start;
	*start = temp;
}
