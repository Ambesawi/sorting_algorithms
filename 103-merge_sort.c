#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - merge and sort the arrays by merging the arry.
 * @array: array to be sorted in merge sort.
 * @copy: copy the array making it for merg.
 * @start: the first index of the arry.
 * @mid: the midle index of the array.
 * @end: the last index of the arry.
 * Return: nothing.
 */
void merge(int *array, int *copy, int start, int mid, int end)
{

	int l1, l2, i = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (l1 = start, l2 = mid; l1 < mid && l2 < end; i++)
		if (array[l1] < array[l2])
			copy[i] = array[l1++];
		else
			copy[i] = array[l2++];
	while (l1 < mid)
		copy[i++] = array[l1++];
	while (l2 < end)
		copy[i++] = array[l2++];
	for (l1 = start, i = 0; l1 < end; l1++)
		array[l1] = copy[i++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * array_divider - divides the array to perform the sort.
 * @array: array to be sorted in merg sort.
 * @copy: copy the array making it for merg.
 * @start: the first index of the arry.
 * @end: the last index of the arry.
 * Return: nothing.
 */
void array_divider(int *array, int *copy, int start, int end)
{
	int midle;

	if (end - start < 2)
		return;

	midle = start + (end - start) / 2;
	array_divider(array, copy, start, midle);
	array_divider(array, copy, midle, end);
	merge(array, copy, start, midle, end);
}

/**
 * merge_sort - implementation of merge sort algorithm
 * @array: array to be sorted in merg sort.
 * @size: size of the array.
 * Return: nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *copy_a;

	if (array == NULL || size < 2)
		return;

	copy_a = malloc(size * sizeof(int));
	if (copy_a == NULL)
		return;

	array_divider(array, copy_a, 0, size);
	free(copy_a);
}
