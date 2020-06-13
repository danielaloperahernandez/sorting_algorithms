#include "sort.h"

/**
 * swap - that sorts a doubly linked list of integers
 * @array: pointers array
 * @size: size value the lengeth
 * @a: integer data
 * @b: integer data
 */
void swap(int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

void bitonic_swap(int *array, size_t size, size_t size_array, size_t left, char flags_result)
{
    int index, jump_array = size_array / 2;


    if (size_array > 1)
    {
        for (index = left; index < (int)(left + size_array); index++)
        {
            if (flags_result == UP && array[index] > array[index + jump_array])
                swap(array + index, array + index + jump_array);
            else if (flags_result == DOWN && array[index] < array[index + jump_array])
                swap(array + index, array + index + jump_array);
        }
        bitonic_swap(array, size, jump_array, left, flags_result);
        bitonic_swap(array, size, jump_array, left + jump_array, flags_result);
    }

}

void bitonic_recursion(int *array, size_t size, size_t left, size_t size_array, char flags)
{
    int middle = size_array / 2;
    char *flags_recursion;

    flags_recursion = (flags == UP) ? "UP" : "DOWN";
    if (size_array > 1)
    {
        printf("Merging [%d/%d] (%s):\n", middle, (int)size, flags_recursion);
        print_array(array + left, size_array);
        bitonic_recursion(array, size, left, middle, UP);
        bitonic_recursion(array, size, left + middle, middle, DOWN);
        bitonic_swap(array, size, size_array, left, flags);
        printf("Result [%d/%d] (%s):\n", (int)size_array, (int)size, flags_recursion);
        print_array(array + left, size_array);
    }
}
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_recursion(array, size, 0, size, UP);
}
