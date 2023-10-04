#include <stdlib.h>
#include <time.h>

#include "sorts.h"
#include "util.h"

static int checkArrayIsSorted(int array[], int length);
static void shuffle(int array[], int length);


int bogoSort(int array[], int length)
{
	int counter = 0;

	do {
		shuffle(array, length);
		counter++;
	} while (!checkArrayIsSorted(array, length));

	return counter;
}

int checkArrayIsSorted(int array[], int length)
{
	for (int i = 1; i < length; i++)
		if (array[i] < array[i - 1])
			return 0;
	return 1;
}

// fisher-random shuffle
void shuffle(int array[], int length)
{
	static int hasSeeded = 0;
	if (!hasSeeded) {
		srandom(time(0));
		hasSeeded = 1;
	}

	for (int i = 0; i < length - 1; i++) { // no point swapping the last item with itself
		int randItem = random() % (length - i) + i;
		swap(&array[i], &array[randItem]);
	}
}
