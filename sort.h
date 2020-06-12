#ifndef _SORT_H_
#define _SORT_H_

/*Librarys standars*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Prints an array and list of integers*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*Function that sorts an array of integers in ascending order*/
void bubble_sort(int *array, size_t size);

/*Function that sorts a doubly linked list of integers in ascending order*/
void insertion_sort_list(listint_t **list);

/*Function that sorts an array of integers in ascending order using*/
void selection_sort(int *array, size_t size);

/*Function that sorts an array of integers in ascending order using*/
void quick_sort(int *array, size_t size);

/*Function that sorts an array of integers in ascending order*/
void shell_sort(int *array, size_t size);

/*Function that sorts a doubly linked list of integers in ascending*/
void cocktail_sort_list(listint_t **list);

#endif /* !_SORT_H_*/
