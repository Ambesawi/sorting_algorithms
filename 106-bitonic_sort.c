#include "sort.h"
#include <stdio.h>

/**
 * bitcompare - compares and swapwith bitcompare algorithm.
 * @array: array to be sorted in bitcompare.
 * @i: size of the array.
 * @j: exponent from the parameter.
 * @dir: direction that is to be compare.
 * Return: nothing
 */
void bitcompare(int *array, int i, int j, int dir)
{
	int swap_p;

	if (dir == (array[i] > array[j]))
	{
		swap_p = array[j];
		array[j] = array[i];
		array[i] = swap_p;
	}
}

/**
 * bitmerge - merges 2 subarrays with bitmerge algorthm.
 * @array: array to be sorted in bitcompare.
 * @low: size of the array.
 * @cnt: exponent from the parameter.
 * @dir: direction that is to be merge.
 * Return: nothing
 */
void bitmerge(int *array, int low, int cnt, int dir)
{
	int i, k;

	if (cnt < 2)
		return;

	k = cnt / 2;

	for (i = low; i < low + k; i++)
		bitcompare(array, i, i + k, dir);
	bitmerge(array, low, k, dir);
	bitmerge(array, low + k, k, dir);
}

/**
 * bitsort - implementation of bitonic sort algorithm.
 * @array: array to be sorted in bitsort.
 * @low: size of the array.
 * @cnt: exponent from the parameter.
 * @dir: direction of sorting
 * @size: size of the array.
 * Return: nothing
 */
void bitsort(int *array, int low, int cnt, int dir, size_t size)
{
	int k;
	char *str;

	if (cnt < 2)
		return;

	k = cnt / 2;

	if (dir == 1)
		str = "UP";
	else
		str = "DOWN";

	printf("Merging [%i/%lu] (%s):\n", cnt, size, str);
	print_array(array, cnt);

	bitsort(array, low, k, 1, size);
	bitsort(array, low + k, k, 0, size);
	bitmerge(array, low, cnt, dir);

	printf("Result [%i/%lu] (%s):\n", cnt, size, str);
	print_array(array, cnt);
}

/**
 * bitonic_sort - implementation of bitonic sort algorithm
 * @array: array to be sorted in bitonic_sort.
 * @size: size of the array.
 * Return: nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitsort(array, 0, size, 1, size);
}
