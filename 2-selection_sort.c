#include "sort.h"

/**
 * selection_sort - selection value in array
 * @array: pointers in integer
 * @size: value data
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min, tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			tmp = array[i];
			array[i] = *min;
			*min = tmp;
			print_array(array, size);
		}
	}
}
