#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void _bitonicMerge(int *array, size_t low, size_t cnt, size_t dir);

/**
 * _bitonicSort - recursively split `array` into smaller bitonic sequences,
 * then merge them into larger bitonic sequences.
 * @array: array to sort
 * @low: lower index of subarray
 * @cnt: number of elements to consider starting from `low`
 * @dir: direction of bitonic subsequence (1 is ascending, 0 is decreasing)
 * @size: size of `array`
 */
void _bitonicSort(int *array, size_t low, size_t cnt, size_t dir, size_t size)
{
	size_t k = cnt / 2;

	if (cnt > 1)
	{
		printf("%s [%lu/%lu] (%s):\n",
		       "Merging",
		       cnt, size,
		       dir ? "UP" : "DOWN");
		print_array(array + low, cnt);
		_bitonicSort(array, low, k, 1, size);
		_bitonicSort(array, low + k, k, 0, size);
		_bitonicMerge(array, low, cnt, dir);
		printf("%s [%lu/%lu] (%s):\n",
		       "Result",
		       cnt, size,
		       dir ? "UP" : "DOWN");
		print_array(array + low, cnt);
	}
}

/**
 * _bitonicMerge - merge subroutine to combine to bitonic sequences into
 * a new bitonic sequence.
 * @array: array on which to operate
 * @low: lower index of subarray
 * @cnt: number of elements in subarray to merge
 * @dir: direction of bitonic subsequence (1 is ascending, 0 is decreasing)
 */
void _bitonicMerge(int *array, size_t low, size_t cnt, size_t dir)
{
	size_t i, k = cnt / 2;
	int tmp;

	if (cnt > 1)
	{
		for (i = low; i < low + k; i++)
		{
			if (!(dir ^ (array[i] > array[i + k])))
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
			}
		}
		_bitonicMerge(array, low, k, dir);
		_bitonicMerge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort - recursive implementation of bitonic sort
 * @array: array to sort
 * @size: size of `array`
 */
void bitonic_sort(int *array, size_t size)
{
	_bitonicSort(array, 0, size, 1, size);
}
