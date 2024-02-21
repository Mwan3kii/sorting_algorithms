#include "sort.h"
#include <stdio.h>
/**
 * quick_sort - Sorts array of integers
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_sort(array, 0, size - 1, size);
}
/**
 * recursive_sort - Quick sort recursively
 * @array: The array
 * @low: The less side of pivot
 * @high: Greater side of pivot
 * @size: Size of array
 */
void recursive_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, size, low, high);
		recursive_sort(array, low, pivot - 1, size);
		recursive_sort(array, pivot + 1, high, size);
	}
}
void swapp(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_partition - The Lomuto partition scheme
 * @array: The array
 * @low: The less side of pivot
 * @high: Greater side of pivot
 * @size: Size of array
 *
 * Return: The element partitioned
 */
int lomuto_partition(int *array, int high, int low, size_t size)
{
	int *pivot;
	int j, i;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swapp(array + i, array + j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swapp(array + 1, pivot);
		print_array(array, size);
	}
	return (i);
}
