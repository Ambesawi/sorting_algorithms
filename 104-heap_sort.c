#include "sort.h"
/**
 * heapify - modify the heap and sort the array.
 * @array: array to be sorted in hepsort.
 * @size: size of the array.
 * @n: size of heap from parameter.
 * @i: root node.
 * Return: nothing.
 */
void heapify(int *array, int n, int i, size_t size)
{
	int largest_l, left_L, right_R;
	int swap;

	largest_l = i;
	left_L = 2 * i + 1;
	right_R = 2 * i + 2;
	if (left_L < n && array[left_L] > array[largest_l])
		largest_l = left_L;
	if (right_R < n && array[right_R] > array[largest_l])
		largest_l = right_R;
	if (largest_l != i)
	{
		swap = array[largest_l];
		array[largest_l] = array[i];
		array[i] = swap;
		print_array(array, size);
		heapify(array, n, largest_l, size);
	}
}


/**
 * heap_sort - implementation of heap sort algorithm
 * @array: array to be sorted
 * @size: array's size.
 * Return: nothing.
 */

void heap_sort(int *array, size_t size)
{
	register int i;
	int swap_a;

	if (!array || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap_a = array[i];
		array[i] = array[0];
		array[0] = swap_a;
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
