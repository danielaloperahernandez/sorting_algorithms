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


int lomuto(int *array, size_t size, ssize_t left, ssize_t right)
{
	ssize_t low = left - 1, fast;
	int pivot = array[right];

	for (fast = left; fast <= right - 1; fast++)
	{
		if (array[fast] <= pivot)
		{
			low += 1;
			swap(array, size, &array[low], &array[fast]);
		}
	}
	/**if (fast > right)**/
		swap(array, size, &array[low + 1], &array[right]);
	return (low + 1);
}

void quick_sort_recursion(int *array, size_t size, ssize_t left, ssize_t right)
{
	size_t part;

	if (left < right)
	{
		part = lomuto(array, size, left, right);

		quick_sort_recursion(array, size, left, part - 1);
		quick_sort_recursion(array, size, part + 1, right);
	}
}
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}
