#include "sorts.h"

static void swap(int* start, int* end);


void slowsort(int array[], int length)
{
	if (length == 1)
		return;

	slowsort(array, length / 2);
	slowsort(array + length / 2, (length + 1) / 2);

	if (array[length / 2 - 1] > array[length - 1])
		swap(array + length / 2 - 1, array + length - 1);

	slowsort(array, length - 1);
}


void swap(int* start, int* end)
{
	int temp = *end;
	*end = *start;
	*start = temp;
}
