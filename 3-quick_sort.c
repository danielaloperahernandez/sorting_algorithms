#include "sort.h"

/**
 * swap - that sorts a doubly linked list of integers
 * @array: pointers array
 * @size: size value the lengeth
 * @a: integer data
 * @b: integer data
 */
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

/**
 * lomuto - partition scheme.
 * @array: pointer array in integers
 * @size: ssize with the array
 * @left: ssize with the array left
 * @right:ssize_t with the array right
 * Return: Always integers
 */
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

/**
 * quick_sort_recursion - partition scheme.
 * @array: pointer array in integers
 * @size: ssize with the array
 * @left: ssize with the array left
 * @right:ssize_t with the array right
 */
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

/**
 * quick_sort - selection value in array
 * @array: pointers in integer
 * @size: value data
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}
