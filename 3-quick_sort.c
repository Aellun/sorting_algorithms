#include "sort.h"
/**
 * this is a function that sorts an array of integers in asc
 * order using quick sort
 */
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps 2 ints of a given array
 * @a: The 1st int to be swapped
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
 * lomuto_partition - using Lomuto partition scheme to order
 * @array: int arrays
 * @size:length size  of array.
 * @left: The starting index of the subset to be ordered.
 * @right: The ending index of the subset to ordered.
 *
 * Returns: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, UpperBound, LowerBound;

	pivot = array + right;
	for (UpperBound = LowerBound = left; LowerBound < right; LowerBound++)
	{
		if (array[LowerBound] < *pivot)
		{
			if (UpperBound < LowerBound)
			{
				swap_ints(array + LowerBound, array + UpperBound);
				print_array(array, size);
			}
			UpperBound++;
		}
	}

	if (array[UpperBound] > *pivot)
	{
		swap_ints(array + UpperBound, pivot);
		print_array(array, size);
	}

	return (UpperBound);
}

/**
 * lomuto_sort - retuns the quicksort algorithm through recursion.
 * @array: array of int to be sorted
 * @size: The length of array.
 * @left: The starting index of the array partition to being ordered.
 * @right: The ending index of the array partition being ordered.
 *
 * Description: Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - using the quicksort algorithm 
 * to Sort an array of integers in ascending
 * @array: An array of int to be sorted
 * @size: The lenght of the array.
 *
 * Description: prints the array after each swap of two elements
 * using Lomuto partition scheme
 *              .
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
