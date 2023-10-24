#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swaps 2 ints in an array.
 * @a: The 1st int to be swapped.
 * @b: The 2nd int to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array:array of integers to be sorted
 * @size: The size of the array to be sorted
 * @start: start index of the sequence in array to sort.
 * @seq: The size of the sequence to be sorted.
 * @flow: The direction of sorting
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t b, jump = seq / 2;

	if (seq > 1)
	{
		for (b = start; b < start + jump; b++)
		{
			if ((flow == UP && array[b] > array[b + jump]) ||
					(flow == DOWN && array[b] < array[b + jump]))
				swap_ints(array + b, array + b + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - turns an array of integers into a bitonic sequence.
 * @array: The int array
 * @size: The length of array
 * @start: start index of a block of  bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t sep = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, sep, UP);
		bitonic_seq(array, size, start + sep, sep, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - using the bitonic sort algorithm to
 * Sort an array of ints in asc order
 * @array: integers array
 * @size: array size
 *
 * Description: Prints the array after each swap, sutable for
 * size = 2^k where k >= 0
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
