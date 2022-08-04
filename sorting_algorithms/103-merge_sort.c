#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


/**
 * top_down_merge - Merges an array that has been split using the
 * top-down approach.
 * @array: The array to merge.
 * @array_c: The temporary array.
 * @l: The left index of the split-array.
 * @m: The mid-point of the split-array.
 * @r: The right index of the split-array.
 */
void top_down_merge(int *array, int *array_c, size_t l, size_t m, size_t r)
{
	size_t a = l, b = m, c;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l, m - l);
	printf("[right]: ");
	print_array(array + (m), r - m);
	for (c = l; c < r; c++)
	{
		if ((a < m) && ((b >= r) || (array_c[a] <= array_c[b])))
		{
			array[c] = array_c[a++];
		}
		else
		{
			array[c] = array_c[b++];
		}
	}
	printf("[Done]: ");
	print_array(array + l, r - l);
}

/**
 * split_merge - Sorts an array that has been split using the
 * merge sort algorithm.
 * @array: The array that has been split.
 * @array_c: The temporary array.
 * @size: The length of the original array.
 * @l: The left index of the split-array.
 * @r: The right index of the split-array.
 */
void split_merge(int *array, int *array_c, size_t size, size_t l, size_t r)
{
	size_t i, mid;

	if ((r - l) <= 1)
		return;
	mid = (l + r) / 2;
	split_merge(array, array_c, size, l, mid);
	split_merge(array, array_c, size, mid, r);
	for (i = l; i <= r + (r == size ? -1 : 0); i++)
		array_c[i] = array[i];
	top_down_merge(array, array_c, l, mid, r);
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *array_c = NULL;

	if (array != NULL)
	{
		array_c = malloc(sizeof(int) * size);
		if (array_c != NULL)
		{
			for (i = 0; i < size; i++)
				array_c[i] = array[i];
			split_merge(array, array_c, size, 0, size);
			free(array_c);
		}
	}
}
