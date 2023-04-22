#include "sorts.h"
#include "util.h"


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
