#include "sort.h"

int get_max(int *array, size_t size);
void count_sort(int *array, int size, int exp);


/**
 * radix_sort - Sorts an array of integers in
 * ascending order using the Radix sort algorithm.
 *
 * @array: An array of integers
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int exp, max;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(array, size, exp);
}

/**
 * get_max - Finds the maximum integer in an array of integers
 *
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: The maximum integer
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - Performs the counting sort of am array of integers
 *
 * @array: An array of integers
 * @size: The size of the array
 * @exp: Significant number
 */
void count_sort(int *array, int size, int exp)
{
	int i, *output, count[10] = { 0 };

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i > -1; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	print_array(array, size);
}
