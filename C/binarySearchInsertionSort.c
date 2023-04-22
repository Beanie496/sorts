#include "sorts.h"
#include "util.h"

 // this inserts the value at end into start
static void insert(int *start, int *end);
static int *search(int *start, int *end);


void binaryInsertionSort(int array[], int length)
{
	int *searchPtr = array;

	while (++searchPtr - array < length)
		insert(search(array, searchPtr), searchPtr);
}


void insert(int *start, int *end)
{
	int temp = *end;

	while (end > start) {
		// this can't be merged with the while statement above, as it can only be
		// decremented if the above statement tests true
		end--;
		*(end + 1) = *end;
	}
	*end = temp;
}


int *search(int *start, int *end)
{
	int *searchPtr = start;
	int temp = *end--;

	// while there is still part of the array left to search, it repeatedly
	// focuses on the half of the array that contains the value
	do {
		if (*searchPtr < temp) {
			start = searchPtr + 1;
			searchPtr = start + (end - start >> 1);
		} else if (*searchPtr > temp) {
			end = searchPtr - 1;
			searchPtr = start + (end - start >> 1);
		}
	// 'start <= end': when the value that needs to be inserted is bigger
	// than all previous values, it needs to be inserted at its own position,
	// which is just past 'end', when it reaches that stage.
	} while (*searchPtr != temp && start <= end);

	// when there is nothing left to search or it's found the value,
	// return the address that the value needs to be inserted in
	if (end < start)
		return start;
	else
		return searchPtr;
}
