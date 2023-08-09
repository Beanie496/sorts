#include <stdlib.h>
#include <time.h>

#include "sorts.h"
#include "util.h"

static void shuffle(int array[], int length);


int bogoSort(int array[], int length)
{
	int counter = 0;
	int sorted = 0;

	srandom(time(0));

	while (!sorted) {
		sorted = 1;

		for (int i = 1; i < length; i++) {
			if (array[i] < array[i - 1]) {
				sorted = 0;
				break;
			}
		}
		shuffle(array, length);
		counter++;
	}
	return counter;
}


// fisher-random shuffle
void shuffle(int array[], int length)
{
	int randItem;
	for (int i = 0; i < length - 1; i++) { // no point swapping the last item with itself
		randItem = random() % (length - i) + i;
		swap(&array[i], &array[randItem]);
	}
}
