#include "sort.h"
#include <stdio.h>
/**
 * quick_sort - Sorts array of integers
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	recursive_sort(array, size, 0, size - 1);
}
/**
 * recursive_sort - Quick sort recursively
 * @array: The array
 * @low: The less side of pivot
 * @high: Greater side of pivot
 * @size: Size of array
 */
void recursive_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (low >= high)
		return;
	part = lomuto_partition(array, size, low, high);
	recursive_sort(array, size, low, part - 1);
	recursive_sort(array, size, part + 1, high);
}
void swap(int *a, int *b)
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
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int j, i = low;

	pivot = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (j != i)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[high], &array[i]);
		print_array(array, size);
	}
	return (i);
}
