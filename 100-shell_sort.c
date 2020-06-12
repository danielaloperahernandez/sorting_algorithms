#include "sort.h"

/**
 * max_gap - return maximus of gap
 * @size: lengeth in the array
 * Return: value size
 */

size_t max_gap(size_t size)
{
	size_t count = 1;

	while (count < size)
		count = count * 3 + 1;
	return ((count - 1) / 3);
}

/**
 * shell_sort - that sorts a doubly linked list of integers
 * @array: Pointers with data
 * @size: size value the lengeth
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || !size)
		return;

	for (gap = max_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
