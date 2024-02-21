#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_top_down - prints left to right
 * @array: The array to sort
 * @size: Size of array
 * @start: Start of array
 * @mid: Middle of array
 */
void print_top_down(int *array, int size, int start, int mid)
{
	int i;

	printf("Merging...\n");
	printf("[left]: ");
	i = start;
	while (i < mid)
	{
		if (i != mid - 1)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
		i++;
	}
	printf("[right]: ");
	i = mid;
	while (i < size)
	{
		if (i < size - 1)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
		i++;
	}
}
/**
 * merge - Mergers the array
 * @array: The array to sort
 * @size: Size of array
 * @start: Start of array
 * @mid: Middle of array
 * @copy: Copy the elem
 */
void merge(int *array, int size, int start, int mid, int *copy)
{
	int i, j, k;

	print_top_down(array, size, start, mid);
	i = start;
	j = mid;

	printf("[Done]: ");
	k = start;
	while (k < size)
	{
		if (i < mid && (j >= size || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i++;
		}
		else
		{
			copy[k] = array[j];
			j++;
		}
		if (k < size - 1)
			printf("%d, ", copy[k]);
		else
			printf("%d\n", copy[k]);
		k++;
	}
}
/**
 * mergeSort - Merges the sort
 * @copy: Copy the elem
 * @start: Start of array
 * @size: Size of array
 * @array: The array
 */
void mergeSort(int *copy, int start, int size, int *array)
{
	int mid;

	if (size - start < 2)
		return;
	mid = (size + start) / 2;
	mergeSort(array, start, mid, copy);
	mergeSort(array, mid, size, copy);
	merge(copy, size, start, mid, array);
}
/**
 * copy_array - Copy the array
 * @arr: Array
 * @copy: The copy
 * @size: Size of array
 */
void copy_array(int *arr, int *copy, int size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		copy[i] = arr[i];
}
/**
 * merge_sort - Merge the sort
 * @array: The array
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	copy = malloc(sizeof(int) * size - 1);
	if (copy == NULL)
		return;
	copy_array(array, copy, size);
	mergeSort(copy, 0, size, array);
	free(copy);
}
