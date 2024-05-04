#include "sort.h"

/**
  * cust_memset- Fills Memory with a constant byte.
  * @s: Pointer to memory area.
  * @b: Byte to fill memory with.
  * @n: Number of bytes to use in memory area.
  * Return: Pointer to memory area s
  */
void *cust_memset(void *s, int b, size_t n)
{
	size_t i;
	unsigned int *ptr = s;

	for (i = 0; i < n; i++)
		ptr[i] = b;
	return (s);
}

/**
  * cust_calloc - Custom function to allocate and set memory block
  * @ptr: Pointer to the meomry block.
  * @size: New Size of memory block
  * Return: Pointer to allocated memory
  */
void *cust_calloc(void *ptr, unsigned int size)
{
	int *newPtr = NULL;

	if (!ptr)
	{
		newPtr = malloc(size);
		if (!newPtr)
			return (NULL);
		cust_memset(newPtr, 0, (size / sizeof(int)));
		return (newPtr);
	}
	return (ptr);
}

/**
 * find_max - This function finds the largest number in an array
 * @array: The array to be searched.
 * @size: The size of the array.
 * Return: Largest num.
 */

int find_max(int *array, size_t size)
{
	int largest = 0;

	while (size-- > 0)
	{
		if (array[size] > largest)
			largest = array[size];
	}
	return (largest);
}

/**
 * counting_sort - This function sorts an array of integers in ascending order,
 * using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size)
{
	size_t i = 0;
	int elem, max_num = 0, *count_array = NULL, *new_array = NULL;

	if (!array || size < 2)
		return;

	max_num = find_max(array, size);

	count_array = cust_calloc(count_array, (sizeof(int) * (max_num + 1)));
	new_array = malloc(sizeof(int) * size);
	if (count_array && new_array)
	{
		for (i = 0; i < size; i++)
			count_array[array[i]]++;

		for (i = 0; i < (size_t) max_num + 1; i++)
			count_array[i] += (i > 0 ? count_array[i - 1] : 0);

		print_array(count_array, max_num + 1);

		for (i = size - 1; (int)i >= 0; i--)
		{
			elem = array[i];
			count_array[elem]--;
			new_array[count_array[elem]] = elem;
		}
		for (i = 0; i < size; i++)
			array[i] = new_array[i];
	}
	free(new_array);
	free(count_array);
}
