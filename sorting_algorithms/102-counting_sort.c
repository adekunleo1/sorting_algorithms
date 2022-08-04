#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void print_array_long(const size_t *, size_t);

/**
 * counting_sort - Counting sort
 * @array: array to evaluate
 * @size: size of array
 * Return: None
 * Note: Most of it works, except for the last count[10]
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, *output;
	size_t i, k, oldCount = 0, *count;

	if (array == NULL || size <= 1)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	k = (size_t)max;
	count = malloc(sizeof(size_t) * (k + 1));
	if (count == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		output[i] = 0;
	for (i = 0; i < size ; i++)
		count[array[i]]++;
	for (i = 1; i <= k; i++)
	{
		oldCount = count[i - 1];
		count[i] = oldCount + count[i];
	}
	print_array_long((const size_t *)count, k + 1);
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}

/**
 * print_array_long - prints array of size_t (unsigned long)
 * @arr: array to print
 * @size: size of `arr`
 */
void print_array_long(const size_t *arr, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%lu", arr[i]);
	}
	putchar('\n');
}
