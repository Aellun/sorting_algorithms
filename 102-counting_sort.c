#include "sort.h"

/**
 * get_max - finds the maximum value in an array of ints.
 * @array: array of ints.
 * @size: The length of the array.
 *
 * Return: The maximum int in the array.
 */
int get_max(int *array, int size)
{
	int max, c;

	for (max = array[0], c = 1; c < size; c++)
	{
		if (array[c] > max)
			max = array[c];
	}

	return (max);
}

/**
 * counting_sort - using the counting sort algorithm
 * Sorts an array of integers in ascending order
 * @array: An array of integers.
 * @size: The length of the array.
 *
 * Description: Prints the counting array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, c;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (c = 0; c < (max + 1); c++)
		count[c] = 0;
	for (c = 0; c < (int)size; c++)
		count[array[c]] += 1;
	for (c = 0; c < (max + 1); c++)
		count[c] += count[c - 1];
	print_array(count, max + 1);

	for (c = 0; c < (int)size; c++)
	{
		sorted[count[array[c]] - 1] = array[c];
		count[array[c]] -= 1;
	}

	for (c = 0; c < (int)size; c++)
		array[c] = sorted[c];

	free(sorted);
	free(count);
}
