#include "sort.h"


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
 * 
 * 
 * 
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tmp, *max, *min;

    if (!list || !*list)
        return;

    tmp = (*list)->next;
    while(tmp)
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