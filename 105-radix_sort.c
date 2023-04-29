#include "sort.h"
#include <stdlib.h>

/**
 * count_sort - implementation of count_sort algorithm.
 * @array: array to be sorted in count_sort.
 * @size: size of the array.
 * @exp: exponent from the parameter.
 * Return: nothing
 */

void count_sort(int *array, int size, int exp)
{
	int *output = NULL;
	int i, counter[10] = {0};

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		counter[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		counter[i] += counter[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[counter[(array[i] / exp) % 10] - 1] = array[i];
		counter[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
/**
 * radix_sort - implementation of radix_sort algorithm.
 * @array: array to be sorted in count_sort.
 * @size: size of the array.
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int max_i, exp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max_i = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max_i)
			max_i = array[i];

	for (exp = 1; max_i / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
