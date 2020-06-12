#include "sort.h"

/**
 * swap - that sorts a doubly linked list of integers
 * @list: doubly Pointers
 * @min: pointers with the value min
 * @max: Doubly Pointers the value
 * @tmp: pointers temporal
 */
void swap(listint_t **list, listint_t *min, listint_t **max, listint_t *tmp)
{
	min->next = tmp->next;
	min->next->prev = tmp->prev;
	tmp->next = (*max)->next->next;
	tmp->prev = *max;
	if (tmp->prev == NULL)
		*list = tmp;
	print_list(*list);
}
/**
 * cocktail_sort_list - print doubly a doubly linked list
 * @list: doubly Pointers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *max, *min;

	if (!list || !*list)
		return;

	tmp = (*list)->next;
	while (tmp)
	{
		min = tmp->next;
		while (min || min->n > tmp->n)
		{
			max = min->prev;
			swap(list, min, &max, tmp);
		}
		tmp = tmp->next;
	}
}
