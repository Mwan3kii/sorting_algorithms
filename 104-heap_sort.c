#include "sort.h"
#include <stdint.h>
#define getLeft(i) (2 * (i) + 1)
#define getRight(i) (2 * (i) + 2)
#define getParent(i) (((i) - 1) / 2)
/**
 * sift_down - Sift down algorithm
 * @array: array with heap
 * @size: size of array
 * @idx: index of index of node of heap
 * @nth: index of nth node in heap
 */
void sift_down(int *array, size_t size, size_t idx, size_t nth)
{
	size_t biggest, left, right;

	do {
		left = getLeft(idx);
		right = getRight(idx);
		biggest = idx;
		if (right <= nth && array[right] > array[idx])
			biggest = right;
		if (array[left] > array[biggest])
			biggest = left;
		if (idx == biggest)
			return;
		array[idx] ^= array[biggest];
		array[biggest] ^= array[idx];
		array[idx] ^= array[biggest];
		print_array(array, size);
		idx = biggest;
	} while (getLeft(idx) <= nth);
}
/**
 * heap_sort - heap sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t node, sortd;

	if (array == NULL || size < 2)
		return;
	for (node = getParent(size - 1); node != SIZE_MAX; node--)
		sift_down(array, size, node, size - 1);
	for (sortd = size - 1; sortd > 1; sortd--)
	{
		array[0] ^= array[sortd];
		array[sortd] ^= array[0];
		array[0] ^= array[sortd];
		print_array(array, size);
		sift_down(array, size, 0, sortd - 1);
	}
	array[0] ^= array[1];
	array[1] ^= array[0];
	array[0] ^= array[1];
	print_array(array, size);
}
