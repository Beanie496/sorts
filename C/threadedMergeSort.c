#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "sorts.h"

typedef struct {
	int *array;
	int length;
} ArrayInfo;

static void *startThreadCreation(void *inputArgsPtr);

static int threadsAvailable;


void threadedMergeSort(int array[], int length)
{
	FILE* tempFile;
	char tempStr[5];
	ArrayInfo initialArguments;

	srand(time(0));

	tempFile = popen("/usr/bin/nproc", "r");
	// TODO: is it 4 or 5? look it up after internet access has been acquired
	fgets(tempStr, 5, tempFile); // As far as I know, there are no regular systems that have over 8192 cores. But just in case...
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

	if (threadsAvailable > 0) {
		// Reserve thread creation
		threadsAvailable--;

		ArrayInfo array1;
		array1.array = inputArgs->array;
		array1.length = inputArgs->length >> 1;

		ArrayInfo array2;
		array2.array = inputArgs->array + array1.length;
		array2.length = inputArgs->length + 1 >> 1;


		pthread_t thread;
		pthread_create(&thread, NULL, startThreadCreation, &array1);
		startThreadCreation(&array2); // Calling the function for the other half directly
		pthread_join(thread, NULL);

		merge(array1.array, array2.array, inputArgs->length);
	} else {
		mergeSort(inputArgs->array, inputArgs->length);
	}

	return NULL;
}
