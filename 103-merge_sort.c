#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sorts a subarray of ints.
 * @subarr: A subarray of an array of ints to be sorted.
 * @buff: A buffer to store the sorted subarray.
 * @front: array front index
 * @mid: array middle index
 * @back: array back index
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t a, m, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (a = front, m = mid; a < mid && m < back; k++)
		buff[k] = (subarr[a] < subarr[m]) ? subarr[a++] : subarr[m++];
	for (; a < mid; a++)
		buff[k++] = subarr[a];
	for (; m < back; m++)
		buff[k++] = subarr[m];
	for (a = front, k = 0; a < back; a++)
		subarr[a] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - execute the merge sort algorithm through recursion.
 * @subarr: int subarray of an array to be sorted
 * @buff: A buffer to store the sorted result.
 * @front: subarray front index
 * @back: subarray back index
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - using the merge sort algorithm
 * Sort an array of int in asc order
 * @array:int array  to be sorted
 * @size: the length of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
