#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The 1st integer to be swap.
 * @b: The 2nd integer to be swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of int that rep a binary tree.
 * @size: The lenght of the array/tree.
 * @base: The base row of the tree index
 * @root: The binary tree root node index
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, middle;

	left = 2 * root + 1;
	right = 2 * root + 2;
	middle = root;

	if (left < base && array[left] > array[middle])
		middle = left;
	if (right < base && array[right] > array[middle])
		middle = right;

	if (middle != root)
	{
		swap_ints(array + root, array + middle);
		print_array(array, size);
		max_heapify(array, size, base, middle);
	}
}

/**
 * heap_sort - using the heap sort algorithm to
 * Sort an array of int in asc order
 * @array: integers array to be sorted
 * @size: array length size
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int item;

	if (array == NULL || size < 2)
		return;

	for (item = (size / 2) - 1; item >= 0; item--)
		max_heapify(array, size, size, item);

	for (item = size - 1; item > 0; item--)
	{
		swap_ints(array, array + item);
		print_array(array, size);
		max_heapify(array, size, item, 0);
	}
}
