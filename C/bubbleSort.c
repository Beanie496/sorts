#include "sorts.h"
#include "util.h"


void bubbleSort(int array[], int length)
{
	int sorted = 0;

	while (!sorted) {
		sorted = 1;
		for (int i = 0; i < length - 1; i++)
			if (array[i] > array[i + 1]) {
				swap(&array[i], &array[i + 1]);
				sorted = 0;
			}
	}
}
