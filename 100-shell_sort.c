#include "sort.h"

/**
 * this is a function that sort array of int in ascending
 * using the shell sort algorithmn(knuth sequence)
 * swap_ints - Swaps 2 ints in an array.
 * @a: 1st int to be to swapped.
 * @b: The 2nd int to be swapped.
 *
 * Description: function that sort array of int in ascending
 * using the shell sort algorithmn(knuth sequence)
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - using the shell sort algorithm Sort an array
 *  of int in asc order
 * @array: An array of int.
 * @size: The length of array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, m, n;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (m = gap; m < size; m++)
		{
			n = m;
			while (n >= gap && array[n - gap] > array[n])
			{
				swap_ints(array + n, array + (n - gap));
				n -= gap;
			}
		}
		print_array(array, size);
	}
}
