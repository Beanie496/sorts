#include <stdlib.h>
#include <string.h>

#include "sorts.h"
#include "util.h"


void mergeSort(int array[], int length)
{
	if (length == 1)
		return;

	mergeSort(array, length / 2);
	mergeSort(array + length / 2, (length + 1) / 2);

	merge(array, array + length / 2, length);
}
