#include "sorts.h"
#include "util.h"

typedef struct {
	int *pos;
	int *firstChild;
	int *secondChild;
	int idx;
} Element;

static void siftDown(int array[], int *startPoint, int length);
static void heapify(int array[], int length);
static void calculateChildren(Element *element);
static void swapWithChild(Element *element, int *child);


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
	Element element = {
		.pos = startPos,
		.idx = startPos - array,
	};
	calculateChildren(&element);

	/*
	 * This loop swaps the current element with the higher of
	 * its two children. If the current position in the binary
	 * tree is such that there aren't two children, this loop stops.
	 *
	 * Logic:
	 * If there is only one child, the right-hand side will be
	 * equal to pos. If there are two, the right-hand side will
	 * be one less. This ensures the loop is broken as soon as
	 * there are fewer than two children.
	 */
	while (element.idx < (length - 1) / 2) {
		if (*element.pos >= *element.firstChild && *element.pos >= *element.secondChild)
			break;

		if (*element.secondChild > *element.firstChild)
			swapWithChild(&element, element.secondChild);
		else
			swapWithChild(&element, element.firstChild);
	}


	// check if there is only one child; swap if needed.
	if (element.firstChild - array == length - 1)
		if (*element.firstChild > *element.pos)
			swap(element.pos, element.firstChild);
}


void calculateChildren(Element *element)
{
	element->firstChild = element->pos + element->idx + 1;
	element->secondChild = element->pos + element->idx + 2;
}


void swapWithChild(Element *element, int *child)
{
	swap(element->pos, child);
	element->idx += child - element->pos;
	element->pos = child;
	calculateChildren(element);
}
