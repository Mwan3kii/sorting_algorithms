#include "sort.h"
#include <stdlib.h>
/**
 * array_max - Maximum array
 * @array: The array
 * @size: Size of array
 *
 * Return: The maximum
 */
int array_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - Sorts using counting sort
 * @array: Array to sort
 * @size: Size of array
 */
void counting_sort(int *array, size_t size)
{
	int *arr, *co_arr, max, num;
	size_t i;

	if (size < 2 || !array)
		return;
	max = array_max(array, size);
	arr = malloc(sizeof(size_t) * (max + 1));
	co_arr = malloc(sizeof(int) * size);
	for (i = 0; (int)i <= max; i++)
		arr[i] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		arr[num] += 1;
	}
	for (i = 1; (int)i <= max; i++)
		arr[i] += arr[i - 1];
	print_array(arr, max + 1);
	for (i = 0; i < size; i++)
	{
		co_arr[arr[array[i]] - 1] = array[i];
		arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = co_arr[i];
	free(co_arr);
	free(arr);
}
