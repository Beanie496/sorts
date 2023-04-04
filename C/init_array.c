#include <stdlib.h>
#include <time.h>

#include "sorts.h"


int *init_array(int length, int range)
{
	int *array = malloc(length * sizeof(int));
	int i;
	
	srand(time(0));
	
	array[0] = rand() % (range + 1);
	// initialising array with random numbers from 0 to 'range'
	for (i = 1; i < length; i++)
		array[i] = rand() % (range + 1);

	return array;
}
