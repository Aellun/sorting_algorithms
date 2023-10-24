#include "sort.h"

/**
 * this function sorts array of integers in ascending order
 * using buble sort algorithm
 * swap_ints - Swaps 2 int in an array.
 * @a: 1st int being swapped
 * @b: 2nd int being swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort aaray of int in asc
 * @array: An array being sorted
 * @size: size of array.
 *
 * Description: Prints array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (a = 0; a < len - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap_ints(array + a, array + a + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
