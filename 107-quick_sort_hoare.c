#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - according to the hoare partition scheme
 *  Order a subset of an array of integers
 *                   .
 * @array: array of integers.
 * @size: array size
 * @left: start index of the subset to order.
 * @right: end index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, upperBound, LowerBound;

	pivot = array[right];
	for (upperBound = left - 1, LowerBound = right + 1; upperBound < LowerBound;)
	{
		do {
			upperBound++;
		} while (array[upperBound] < pivot);
		do {
			LowerBound--;
		} while (array[LowerBound] > pivot);

		if (upperBound < LowerBound)
		{
			swap_ints(array + upperBound, array + LowerBound);
			print_array(array, size);
		}
	}

	return (upperBound);
}

/**
 * hoare_sort - execute the quicksort algorithm through recursion.
 * @array: integers array to sort.
 * @size: array size to sort
 * @left: start index of the array partition to order.
 * @right:  end index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - using the quicksort algorithm
 * Sort an array of integers in asc order.
 * @array: integers array to order
 * @size: array size to order
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
