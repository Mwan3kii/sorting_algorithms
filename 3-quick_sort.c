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
		pivot = lomuto_partition(array, low, high, size);
		recursive_sort(array, low, pivot - 1, size);
		recursive_sort(array, pivot + 1, high, size);
	}
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
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i + 1);
}
