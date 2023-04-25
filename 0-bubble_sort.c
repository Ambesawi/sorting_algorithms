#include "sort.h"

/**
 * bubble_sort - perform sorting using bubble sort method by dividing.
 * @array: array to be sorted from the parameter.
 * @size: size of the array.
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	int swap_p, swapped_p;
	size_t i;

	if (array == NULL || size < 2)
		return;

	while (swapped_p)
	{
		swapped_p = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swapped_p = 1;
				swap_p = array[i + 1];
				array[i + 1] = array[i];
				array[i] = swap_p;
				print_array(array, size);
			}
		}
	}
}
