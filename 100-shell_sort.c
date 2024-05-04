#include "sort.h"

/**
 * shell_sort - This function sorts an array of integers in ascending order,
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, interval = 1;
	int temp = 0;

	if (!array || size < 2)
		return;

	while (interval < size / 3)
		interval = (interval * 3) + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			for (j = i; j >= interval && array[j - interval] > array[j]; j -= interval)
			{
				temp = array[j];
				array[j] = array[j - interval];
				array[j - interval] = temp;
			}
		}
		interval /= 3;
		print_array(array, size);
	}
}
