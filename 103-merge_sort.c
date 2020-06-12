#include "sort.h"

void merge_swap(int *new_array, int *array, size_t left, size_t right)
{
    size_t middle = (left + right) / 2;
    size_t i = 0, j = 0, index;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, middle - left);
    printf("[rigth]: ");
    print_array(array + right, right - middle);

    for ( ; i <= left && j <= right; )
    {
        if (array[i] <= array[j])
        {
            new_array[index] = array[i];
            i++;
        }
        else
        {
            new_array[index] = array[j];
            j++;
        }
        index++;
    }
    while (i < left)
    {
        new_array[index] = array[i];
        index++;
        i++;
    }
    while (j < right)
    {
        new_array[index] = array[j];
        index++;
        j++;
    }
    /*for (i = left; index < right; index++)
    {
        if (i < middle && (j >= right || array[i] <= array[j]))
        {
            new_array[index] = array[i];
            i++;
        }
        else
        {
            new_array[index] = array[j];
            j++;
        }
    } */

    for (i = 0; new_array; i++)
        array[i] = new_array[i];
    printf("[Done]: ");
    print_array(array, right - left);
    
}
void merge_recursion(int *new_array, int *array, size_t left, size_t right)
{
    size_t middle = (left + right) / 2;

    if ((right - left) < 2)
        return;  
    merge_recursion(new_array, array, left, middle);
    merge_recursion(new_array, array, middle + 1, right);
    merge_swap(new_array, array, left, right);
}


void merge_sort(int *array, size_t size)
{
    int *new_array;

    if (!array || size < 2)
        return;
    
    new_array = malloc(sizeof(int) * size);
    if (!new_array)
        return;

    merge_recursion(new_array, array, 0, size); 
}