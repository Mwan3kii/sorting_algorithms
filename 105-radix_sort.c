#include "sort.h"
/**
 * get_max - gets the max num in an array
 * @array: the array
 * @size: the size of the array
 * Return: the max number
 */
int get_max(int *array, size_t size)
{
	int num = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > num)
			num = array[i];
	}
	return  (num);
}
/**
 * count_Sort - counting sort on the specified digit
 * @array: array to sort
 * @size: size of the array
 * @exp: current digit to process
 */
void count_Sort(int *array, size_t size, size_t exp)
{
	int *result = malloc(size * sizeof(int));
	size_t i;
	int count[10] = {0};

	if (result == NULL)
		return;
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i < size; i--)
	{
		result[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = result[i];
	print_array(array, size);
	free(result);
}
/**
 * radix_sort - radix sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	size_t exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_Sort(array, size, exp);
	}
}
