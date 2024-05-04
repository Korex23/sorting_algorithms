#include "sort.h"

void swap_ints(int *a, int *b);
void heapify(int *array, size_t size, size_t n, size_t i);

/**
 * heap_sort - Sort an array of integers in ascending
 * order using the heap sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}

/**
 * heapify - Turn a array to a heap
 * @array: An array of integers
 * @size: The size of the array/tree
 * @n: Number of parent and children
 * @i: The node
 */
void heapify(int *array, size_t size, size_t n, size_t i)
{
	size_t largest, l, r;

	largest = i;
	l = (2 * i) + 1;
	r = (2 * i) + 2;

	if (l < n && array[l] > array[largest])
		largest = l;
	if (r < n && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		swap_ints(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, n, largest);
	}
}

/**
 * swap_ints - Swap two integers
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
