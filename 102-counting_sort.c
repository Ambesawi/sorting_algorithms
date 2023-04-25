#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - using the counting_sort to sort the array.
 * @array: array to be sorted in counting_sort.
 * @size: size of thr array.
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int i, max_num;
	size_t j;
	int *output_p = NULL, *counter = NULL;

	if (array == NULL || size < 2)
		return;

	output_p = malloc((size + 1) * sizeof(int));
	if (output_p == NULL)
		return;

	max_num = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max_num)
			max_num = array[j];
	}

	counter = malloc((max_num + 1) * sizeof(int));
	if (counter == NULL)
	{
		free(output_p);
		return;
	}

	for (j = 0; j < size; j++)
		counter[array[j]]++;
	for (i = 1; i <= max_num; i++)
		counter[i] += counter[i - 1];
	print_array(counter, max_num + 1);
	for (j = 0; j < size; j++)
	{
		output_p[counter[array[j]] - 1] = array[j];
		counter[array[j]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = output_p[j];
	free(counter);
	free(output_p);
}
