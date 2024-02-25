#include "sort.h"

#define UP 1
#define DOWN 0

void int_swap(int *a, int *b);
void bit_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);
/**
 * int_swap - Swapps ints in array
 * @a: The first integer
 * @b: The second integer
 */
void int_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * bit_merge - sorts array in bitonic sequence
 * @array: An array of integers
 * @size: The size of the array.
 * @start: The starting index of the sequence
 * @seq: the size of the sequence to sort
 * @flow: the direction to sort
 */
void bit_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t j, jump = seq / 2;

	if (seq > 1)
	{
		for (j = start; j < start + jump; j++)
		{
			if ((flow == UP && array[j] > array[j + jump]) ||
				(flow == DOWN && array[j] < array[j + jump]))
			{
				int_swap(array + j, array + j + jump);
			}
		}
		bit_merge(array, size, start, jump, flow);
		bit_merge(array, size, start + jump, jump, flow);
	}
}
/**
 * bit_sequence - converts in bitonic sequence
 * @array: An array of integers
 * @size: The size of the array.
 * @start: The starting index
 * @seq: The size of a block bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bit_sequence(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *string = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);
		bit_sequence(array, size, start, cut, UP);
		bit_sequence(array, size, start + cut, cut, DOWN);
		bit_merge(array, size, start, seq, flow);
		printf("Result [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);
	}
}
/**
 * bitonic_sort - Sorts bitonic
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sequence(array, size, 0, size, UP);
}
