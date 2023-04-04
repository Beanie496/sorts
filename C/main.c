#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorts.h"


int main(int argc, char *argv[])
{
	int *array;
	int length;

	// 100,000,000
	length = 100000000;
	array = initArray(length, 1000);
	printArray(array, length);
	printf("Binary radix sort:\n");
	binaryRadixSort(array, length);
	printf("Sorted.\n");
	printArray(array, length);
	free(array);

	return 0;
}
