#include "sort.h"

/**
 * selection_sort - This function sorts an array of integers
 * in ascending order, using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, smallest_elem_index = 0;
	int tmp = 0;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		smallest_elem_index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[smallest_elem_index])
				smallest_elem_index = j;

			/*If at the end of loop, swap smallest element*/
			if (j + 1 == size && smallest_elem_index != i)
			{
				tmp = array[smallest_elem_index];
				array[smallest_elem_index] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
}
