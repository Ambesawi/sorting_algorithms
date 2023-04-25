#include "sort.h"

/**
 * shell_sort - using the shell_sort to sort the array.
 * @array: array to be sorted in shell_sort.
 * @size: size of thr array.
 * Return: nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap_p = 1;
	int swap_p;

	if (array == NULL || size < 2)
		return;

	while (gap_p < size / 3)
		gap_p = 3 * gap_p + 1;

	while (gap_p > 0)
	{
		for (i = gap_p; i < size; i++)
		{
			swap_p = array[i];
			for (j = i; j >= gap_p && array[j - gap_p] > swap_p; j -= gap_p)
			{
				array[j] = array[j - gap_p];
			}
			array[j] = swap_p;
		}
		gap_p = (gap_p - 1) / 3;
		print_array(array, size);
	}
}
