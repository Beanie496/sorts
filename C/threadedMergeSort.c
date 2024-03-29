#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "sorts.h"
#include "util.h"

typedef struct {
	int *array;
	int length;
} ArrayInfo;

static void *startThreadCreation(void *inputArgsPtr);
static void concurrentlySortArray(ArrayInfo *inputArgs);
static void concurrentlySortTwoArrays(ArrayInfo array1, ArrayInfo array2);

static int threadsAvailable;


void threadedMergeSort(int array[], int length)
{
	FILE* tempFile;
	char tempStr[5];
	ArrayInfo initialArguments;

	srand(time(0));

	tempFile = popen("/usr/bin/nproc", "r");
	// As far as I know, there are no regular systems that have over 8192
	// cores. But just in case...
	fgets(tempStr, 5, tempFile);
	pclose(tempFile);
	// subtract one for the main thread
	threadsAvailable = atoi(tempStr) - 1;

	initialArguments.array  = array;
	initialArguments.length = length;

	startThreadCreation(&initialArguments);
}


void *startThreadCreation(void *inputArgsPtr)
{
	/* Each time this function is called, it either performs a merge sort on the part
	 * of the array it's given, or, if there still aren't enough recursed functions
	 * (there will be 2**depth currently-running functions, thanks to each function
	 * creating a thread when recursed) it calls a thread to sort one half of the array
	 * (by recursion, if depth is not high enough, or just by sorting it)  while it
	 * sorts the other half. When a given thread has finished, it just terminates.
	 */

	ArrayInfo *inputArgs = inputArgsPtr;

	if (inputArgs->length == 1)
		return NULL;

	if (threadsAvailable > 0)
		concurrentlySortArray(inputArgs);
	else
		mergeSort(inputArgs->array, inputArgs->length);

	return NULL;
}


void concurrentlySortArray(ArrayInfo *inputArgs)
{
	// Reserve thread creation
	threadsAvailable--;

	ArrayInfo array1 = {
		inputArgs->array,
		inputArgs->length / 2,
	};

	ArrayInfo array2 = {
		inputArgs->array + array1.length,
		(inputArgs->length + 1) / 2,
	};

	concurrentlySortTwoArrays(array1, array2);

	merge(array1.array, array2.array, inputArgs->length);
}


void concurrentlySortTwoArrays(ArrayInfo array1, ArrayInfo array2)
{
	pthread_t thread;
	pthread_create(&thread, NULL, startThreadCreation, &array1);
	// Calling the function for the other half directly
	startThreadCreation(&array2);
	pthread_join(thread, NULL);
}
