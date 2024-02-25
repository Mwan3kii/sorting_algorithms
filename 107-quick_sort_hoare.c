#include "sort.h"
/**
 * hoare_partition - Partitions array
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 * Return: int pivot index
 */
int hoare_partition(int *array, int first, int last, size_t size)
{
	int pivot = array[last], n = first - 1, j = last + 1, aux;

	while (1)
	{
		do {
			n++;
		} while (array[n] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (j < n)
			return (j);
		if (array[n] > array[j])
		{
			aux = array[n];
			array[n] = array[j];
			array[j] = aux;
			print_array(array, size);
		}
	}
}
/**
 * sorts_recursive - sorts an array recursively
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 */
void sorts_recursive(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = hoare_partition(array, first, last, size);
		sorts_recursive(array, first, pivot, size);
		sorts_recursive(array, pivot + 1, last, size);
	}
}
/**
 * quick_sort_hoare - sorts array using the Quick algorithm
 * @array: array to sort
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sorts_recursive(array, 0, size - 1, size);
}
