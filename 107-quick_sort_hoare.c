#include "sort.h"
#include <sys/types.h>

/**
 * partition - divides the array and swap datas and partition.
 * @array: array to be sorted in partition argorithm.
 * @low: first index of the array.
 * @high: last index of the array.
 * @size: size of the array.
 * Return: nothing
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot_p = array[low], swap;
	ssize_t i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot_p);
		do {
			j--;
		} while (array[j] > pivot_p);
		if (i >= j)
			return (j);
		swap = array[j];
		array[j] = array[i];
		array[i] = swap;
		print_array(array, size);
	}
}

/**
 * quicksort - divides the array to perform the sorting in quicksort.
 * @array: array to be sorted in quicksort algorthm.
 * @low: first index of the array.
 * @high: last index of the array.
 * @size: size of the array.
 * Return: nothing
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - perform an incremental sorting in quick_sort_hoare.
 * @array: rray to be sorted in quicksort algorthm.
 * @size: size of the array.
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
