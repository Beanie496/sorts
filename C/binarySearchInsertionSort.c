#include <string.h>

#include "sorts.h"
#include "util.h"

 // this inserts the value at value into start, moving all ints forwards by one
static void insert(int *insert, int *value);
static int *binarySearch(int *array, int *length, int *value);


void binaryInsertionSort(int array[], int length)
{
	int *searchPtr = array;

	while (++searchPtr - array <= length)
		insert(binarySearch(array, searchPtr - 1, searchPtr), searchPtr);
}


void insert(int *insert, int *value)
{
	// { X, X, X, v }
	int temp = *value;
	// { -, X, X, X }
	memmove(insert + 1, insert, (value - insert) * sizeof(*value));
	// { v, X, X, X }
	*insert = temp;
}


// returns a pointer to the value found in the array. Otherwise, it returns a
// pointer to the smallest value that is larger than the value being found.
int *binarySearch(int *start, int *end, int *value)
{
        while (end > start) {
                int *mid = start + ((end - start) >> 1);
                if (*mid == *value)
                        return mid;
                if (*mid > *value)
                        end = mid - 1;
                else
                        start = mid + 1;
        }
        return start;
}
