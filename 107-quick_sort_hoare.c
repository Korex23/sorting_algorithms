#include "sort.h"

void quick_sort_recursion(int *array, size_t size, int low, int high);
size_t partition(int *array, size_t size, size_t low, size_t high);

/**
 * quick_sort_hoare - Sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: An array of integers
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_recursion(array, size, 0, size - 1);
}

/**
 * quick_sort_recursion - This function is called recursively to implement the
 * to implement the quick sort algorithm
 * @low: Starting point to begin sorting partition.
 * @high: End of partition.
 * @array: The array to be sorted.
 * @size: Size of entire array
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, size, low, high);
		quick_sort_recursion(array, size, low, pivot_index - 1);
		quick_sort_recursion(array, size, pivot_index, high);
	}
}


/**
 * partition - This function partitions the given array and
 * sorts the pivot in correct position.
 * It uses the Hoare partition scheme with last elem as pivot.
 * @array: The array to be sorted.
 * @low: Starting point to begin sorting partition.
 * @high: End of partition.
 * @size: Size of entire array
 * Return: Location of pivot after sorting.
 */
size_t partition(int *array, size_t size, size_t low, size_t high)
{
	int tmp, pivot_value = array[high];
	size_t i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot_value);
		do {
			j--;
		} while (array[j] > pivot_value);

		if (i < j)
		{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
		}
		else
			return (i);
	}
}
