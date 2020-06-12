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
int hoare(int *array, size_t size, ssize_t left, ssize_t right)
{
	int pivot;
	size_t asc = left - 1, des = right + 1;

	pivot = array[right];
	while(1)
	{
		do{
			asc++;
		}while(array[asc] < pivot);

		do{
			des--;
		}while(array[des] > pivot);

		if (asc >= des)
			break;
		swap(array, size, &array[asc], &array[des]);
	}
	return (asc);
}
	/*
	size_t i = left - 1, j = right;
	int pivot = array[left];

	while (i < size - 1)
	{
		while (array[i] < pivot)
			i++;
		while(array[j] > pivot)
			j--;

		if (i < j)
			swap(array, size, &array[j], &array[i]);
		else if (i >= j)
			break;
	}
	return (i + 1);
	*/


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
		part = hoare(array, size, left, right);
		quick_sort_recursion(array, size, left, part - 1);
		quick_sort_recursion(array, size, part, right);

	}
}

/**
 * quick_sort - selection value in array
 * @array: pointers in integer
 * @size: value data
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}
