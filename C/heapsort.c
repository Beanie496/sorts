#include "sorts.h"

static void siftDown(int array[], int *startPoint, int length);
static void heapify(int array[], int length);
static void swap(int *p1, int *p2);


void heapsort(int array[], int length)
{
	int temp;
	int *end = array + length - 1;


	heapify(array, length);

	while (array < end) {

		temp = *end;
		*end = array[0];
		array[0] = temp;

		length--;
		end--;

		siftDown(array, array, length);

	}
}


void heapify(int array[], int length)
{
	int *end = array + (length >> 1);

	while (end > array)
		siftDown(array, --end, length);
}


void siftDown(int array[], int *startPos, int length)
{
	int pos = startPos - array;
	int newPos;
	int posOfFirstChild = (pos << 1) + 1;


	/*
	 * This loop swaps the current element with the higher of
	 * its two children. If the current position in the binary
	 * tree is such that there aren't two children, this loop stops.
	 * After that, it checks if there was only one child and swaps
	 * with it if needed.
	 *
	 * Logic behind this logical statement:
	 * If there is only one child, the right-hand side will be
	 * equal to pos. If there are two, the right-hand side will
	 * be one less. This ensures the loop is broken as soon as
	 * there are fewer than two children.
	 */
	while (pos < length - 1 >> 1) {
		if (!(array[pos] < array[posOfFirstChild] || array[pos] < array[posOfFirstChild + 1]))
			break;

		if (array[posOfFirstChild + 1] > array[posOfFirstChild])
			newPos = posOfFirstChild + 1;
		else
			newPos = posOfFirstChild;
		swap(&array[pos], &array[newPos]);
		pos = newPos;

		posOfFirstChild = (pos << 1) + 1;
	}


	if (posOfFirstChild == length - 1)
		if (array[posOfFirstChild] > array[pos])
			swap(&array[pos], &array[posOfFirstChild]);
}


void swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
