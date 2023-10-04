#include "sorts.h"
#include "util.h"


void bubbleSort(int array[], int length)
{
	int sorted = 0;

	for (int j = length - 1; j > 1 && !sorted; j--) {
		sorted = 1;
		for (int i = 0; i < j; i++)
			if (array[i] > array[i + 1]) {
				swap(&array[i], &array[i + 1]);
				sorted = 0;
			}
	}
}
