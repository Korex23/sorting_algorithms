#include "sort.h"

void b_sort(int *array,	size_t size, size_t low, size_t count, int direction);
void b_merge(int *array, size_t low, size_t count, int direction);

/**
 * bitonic_sort - Sorts an array of integers in
 * ascending order using the Bitonic sort algorithm
 *
 * @array: An array of integers
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	b_sort(array, size, 0, size, 1);
}

/**
 * b_sort - This function is called recursively to
 * implement the to implement the bitonic sort algorithm
 *
 * @array: The entire array
 * @size: Size of the entire array
 * @low: The start of the sequence
 * @count: Number count of the sequence
 * @direction: 1 for ascending and 0 for descending
 */
void b_sort(int *array, size_t size, size_t low, size_t count, int direction)
{
	size_t k;

	if (count > 1)
	{
		printf("Merging [%ld/%ld] ", count, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(&array[low], count);
		k = count / 2;
		b_sort(array, size, low, k, 1);
		b_sort(array, size, low + k, k, 0);
		b_merge(array, low, count, direction);

		printf("Result [%ld/%ld] ", count, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(&array[low], count);
	}
}

/**
 * b_merge - This function is called recursively to
 * implement the to implement the bitonic sort algorithm
 *
 * This merges the bitonic sequences
 *
 * @array: The entire array
 * @low: The start of the sequence
 * @count: Number count of the sequence
 * @direction: 1 for ascending and 0 for descending
 */

void b_merge(int *array, size_t low, size_t count, int direction)
{
	size_t k, i;
	int tmp;

	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < low + k; i++)
		{
			if (direction == (array[i] > array[i + k]))
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
			}
		}
		b_merge(array, low, k, direction);
		b_merge(array, low + k, k, direction);
	}
}
