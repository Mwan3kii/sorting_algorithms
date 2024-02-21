#include "sort.h"
/**
 * shell_sort - Sort using the Knuth sequence
 * @array: The array to sort
 * @size: Size of array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, temp;

	while (gap < ((int)(size)))
		gap = (3 * gap) + 1;
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i += 1)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
