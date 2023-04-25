#include "sort.h"
#include <sys/types.h>

/**
 * partition_divide - divides the array to 2 and swap the content.
 * @array: array to be sorted in quicksort.
 * @low: first index of the list or the array.
 * @high: last index of the list or the array.
 * @size: size of the array.
 * Return: nothing
 */

size_t partition_divide(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high], swaped;
	ssize_t i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swaped = array[j];
				array[j] = array[i];
				array[i] = swaped;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swaped = array[i + 1];
		array[i + 1] = array[high];
		array[high] = swaped;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - divides the array to perform sorting in quicksort.
 * @array: array to be sorted in quicksort.
 * @low: first index of the list or the array.
 * @high: last index of the list or the array.
 * @size: size of the array.
 * Return: nothing
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pt;

	if (low < high)
	{
		pt = partition_divide(array, low, high, size);
		quicksort(array, low, pt - 1, size);
		quicksort(array, pt + 1, high, size);
	}
}

/**
 * quicksort - divides the array to perform sorting in quicksort.
 * @array: array to be sorted in quicksort.
 * @size: size of the array.
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
