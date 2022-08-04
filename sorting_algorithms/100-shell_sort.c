#include "sort.h"

/**
 * shell_sort - shell sorting algorithm using insertion sort on subarrays
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, k;
	int tmp;

	for (gap = 1; gap < size; gap = 3 * gap + 1)
		;
	for (gap /= 3; gap > 0; gap /= 3)
	{
		for (i = 0; i < gap; i++)
		{
			j = i;
			while (j < size - gap)
			{
				if (array[j] > array[j + gap])
				{
					tmp = array[j];
					array[j] = array[j + gap];
					array[j + gap] = tmp;
					for (k = j; k >= gap; k -= gap)
					{
					if (array[k] < array[k - gap])
					{
					tmp = array[k];
					array[k] = array[k - gap];
					array[k - gap] = tmp;
					}
					else
					break;
					}
				}
				else
					j += gap;
			}
		}
		print_array(array, size);

	}
}
