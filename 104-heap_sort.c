#include "sort.h"

void swap(int *array, size_t size, int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

void heap_search(int *array, size_t size, size_t down, size_t root)
{
	size_t child_left, child_right, max;

	child_left = 2 * root + 1;
	child_right = 2 * root + 2;
	max = root;

	if (child_left < down && array[child_left] > array[max])
		max = child_left;
	
	if (child_right < down && array[child_right] > array[max])
		max = child_right;

	if (max != root)
	{
		swap(array, size, array + root, array + max);
		heap_search(array, size, down, max);
	}
}


void heap_sort(int *array, size_t size)
{
	int index;

	if(!array || size < 2)
		return;

	for (index = (size / 2) - 1; index >= 0; index--)
		heap_search(array, size, size, index);

	for (index = size - 1; index > 0; index--)
	{
		swap(array, size, array, array + index);
		heap_search(array, size, index, 0);
	}
}