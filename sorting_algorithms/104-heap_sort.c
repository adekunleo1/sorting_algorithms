#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


void buildMaxHeap(int *, size_t);
void siftDown(int *, size_t, size_t, size_t);
void heap_sort(int *, size_t);

/**
 * buildMaxHeap - take unsorted array and convert to complete
 * binary tree with heap property.
 * @array: array to convert
 * @size: size of array
 */
void buildMaxHeap(int *array, size_t size)
{
	size_t root;

	if (!array || size < 2)
		return;
	root = size / 2;
	do {
		root--;
		siftDown(array, root, size, size);
	} while (root);
}

/**
 * siftDown - move root at index `root` in `heap` into correct position
 * @heap: heap structure to sift
 * @root: index of root to sift
 * @end: last index to consider
 * @size: size of heap
 */
void siftDown(int *heap, size_t root, size_t end, size_t size)
{
	int tmp;
	size_t left, right, largest;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	if (left < end && heap[left] > heap[largest])
		largest = left;
	if (right < end && heap[right] > heap[largest])
		largest = right;
	if (largest != root)
	{
		tmp = heap[root];
		heap[root] = heap[largest];
		heap[largest] = tmp;
		print_array(heap, size);
		siftDown(heap, largest, end, size);
	}
}

/**
 * heap_sort - implementation of heap sort algorithm on `array`
 * @array: array to sort
 * @size: size of `array`
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (array == NULL || size < 2)
		return;
	buildMaxHeap(array, size);
	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		siftDown(array, 0, i, size);
	}
}
