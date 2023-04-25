#include "sort.h"

/**
 * selection_sort - perform sorting using selection_sort.
 * @array: array to be sorted based on selection_sort.
 * @size: size of the array.
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, Min_index;
	int swap_p;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		Min_index = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[Min_index])
				Min_index = j;

		if (i != Min_index)
		{
			swap_p = array[Min_index];
			array[Min_index] = array[i];
			array[i] = swap_p;
			print_array(array, size);
		}
	}
}
