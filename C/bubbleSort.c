#include "sorts.h"

static inline void swap(int *p1, int *p2);


void bubbleSort(int array[], int length)
{
	int sorted = 0;

	while (!sorted) {
		sorted = 1;
		for (int i = 0; i < length - 1; i++) {
			if (array[i] > array[i + 1]) {
				swap(&array[i], &array[i + 1]);
				sorted = 0;
			}
		}
	}
}


void swap(int *pointer1, int *pointer2)
{
	int temp = *pointer2;
	*pointer2 = *pointer1;
	*pointer1 = temp;
}
