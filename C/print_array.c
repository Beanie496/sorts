#include <stdio.h>

#include "sorts.h"


void print_array(int *array, int length)
{
	print("%d", array[0]);
	for (int i = 0; i < length; i++)
		printf(", %d", array[i]);
}
