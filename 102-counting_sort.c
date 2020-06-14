#include "sort.h"

/**
 * max_num - function reutrn max integer
 * @array: pointers array
 * @size: size value the lengeth
 * Return: integer data
 */
int max_num(int *array, int size)
{
	int max_num, j;

	for (max_num = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max_num)
			max_num = array[j];
	}
	return (max_num);
}

/**
 * counting_sort - function counting function
 * @array: pointers array
 * @size: size value the lengeth
 * Return: integer data
 */
void counting_sort(int *array, size_t size)
{
	int *count, *final, max, index;

	if (!array || size < 2)
		return;

	final = malloc(sizeof(int) * size);
	if (final == NULL)
		return;

	max = max_num(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(final);
		return;
	}
	for (index = 0; count[index]; index++)
		count[index] = 0;

	for (index = 0; index < (int)size; index++)
		count[array[index]] += 1;

	for (index = 0; index < max + 1; index++)
		count[index] += count[index - 1];

	print_array(count, max + 1);

	for (index = 0; index < (int)size; index++)
	{
		final[count[array[index]] - 1] = array[index];
		count[array[index]] -= 1;
	}
	for (index = 0; index < (int)size; index++)
		array[index] = final[index];

	free(final);
	free(count);
}
