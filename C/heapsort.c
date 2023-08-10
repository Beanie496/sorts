#include "sorts.h"
#include "util.h"

static void siftDown(int array[], int *startPoint, int length);
static void heapify(int array[], int length);


void heapsort(int array[], int length)
{
	int *end = array + length - 1;

	heapify(array, length);

	while (array < end) {
		swap(&array[0], end);
		length--;
		end--;
		siftDown(array, array, length);
	}
}


void heapify(int array[], int length)
{
	int *end = array + length / 2;

	while (end > array)
		siftDown(array, --end, length);
}


void siftDown(int array[], int *startPos, int length)
{
	int pos = startPos - array;
	int newPos;
	int posOfFirstChild = pos * 2 + 1;
	int posOfSecondChild = pos * 2 + 2;


	/*
	 * This loop swaps the current element with the higher of
	 * its two children. If the current position in the binary
	 * tree is such that there aren't two children, this loop stops.
	 * After that, it checks if there was only one child and swaps
	 * with it if needed.
	 *
	 * Logic:
	 * If there is only one child, the right-hand side will be
	 * equal to pos. If there are two, the right-hand side will
	 * be one less. This ensures the loop is broken as soon as
	 * there are fewer than two children.
	 */
	while (pos < (length - 1) / 2) {
		if (array[pos] >= array[posOfFirstChild] && array[pos] >= array[posOfSecondChild])
			break;

		if (array[posOfFirstChild + 1] > array[posOfFirstChild])
			newPos = posOfSecondChild;
		else
			newPos = posOfFirstChild;

		swap(&array[pos], &array[newPos]);
		pos = newPos;

		posOfFirstChild = pos * 2 + 1;
		posOfSecondChild = pos * 2 + 2;
	}


	if (posOfFirstChild == length - 1)
		if (array[posOfFirstChild] > array[pos])
			swap(&array[pos], &array[posOfFirstChild]);
}
