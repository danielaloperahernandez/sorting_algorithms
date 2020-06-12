#include "sort.h"

/**
 * swap - that sorts a doubly linked list of integers
 * @list: doubly Pointers
 * @min: pointers with the value min
 * @max: Doubly Pointers the value
 */
void swap(listint_t **list, listint_t *min, listint_t **max)
{
	(*max)->next = min->next;
	if (min->next)
		min->next->prev = *max;
	min->prev = (*max)->prev;
	min->next = *max;
	if ((*max)->prev)
		(*max)->prev->next = min;
	else
		*list = min;
	(*max)->prev = min;
	*max = min->prev;
	print_list(*list);
}

/**
 * insertion_sort_list - that sorts a doubly linked list
 * @list: doubly Pointers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *min, *max, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	for (min = (*list)->next; min; min = temp)
	{
		temp = min->next;
		max = min->prev;

		while (max && min->n < max->n)
		{
			swap(list, min, &max);
		}
	}
}
