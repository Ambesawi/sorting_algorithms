#include <stdio.h>
#include <stddef.h>

/**
 * print_array - print the array to perform print_array.
 * @array: array to beprinted.
 * @size: size of the array.
 * Return: nothing
 */

void print_array(const int *array, size_t size)
{
	size_t j;
	
	j = 0;
	while (array && j < size)
	{
		if (j > 0)
			printf(", ");
		printf("%d", array[j]);
		++j;
	}
	printf("\n");
}

/**
 * cocktail_sort - sort the array to perform cocktail_sort.
 * @array: array to be sorted in cocktail_sort.
 * @size: size of the array.
 * Return: nothing
 */
void cocktail_sort(int *array, size_t size)
{
	int swaped = 1;
	size_t i = 0, j = size - 1, k;
	int swap_p;

	while (i < j && swaped)
	{
		swaped = 0;
		for (k = i; k < j; k++)
		{
			if (array[k] > array[k + 1])
			{
				swap_p = array[k];
				array[k] = array[k + 1];
				array[k+ 1] = swap_p;
				print_array(array, size);
				swaped = 1;
			}
		}
		j--;
		if(swaped)
		{
			swaped = 0;
			for (k = j; k > i; k--)
			{
				if(array[k] < array[k - 1]) 
				{
					swap_p = array[k];
					array[k] = array[k - 1];
					array[k - 1] = swap_p;
					print_array(array, size);
					swaped = 1;
				}
			}
		}
		i++;
	}
}

int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	cocktail_sort(array, n);
	printf("\n");
	print_array(array, n);
	
	return (0);
}
