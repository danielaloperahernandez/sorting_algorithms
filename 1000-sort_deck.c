#include "deck.h"
#include "stdio.h"
/**
 * index_search - gets index
 * @card_1: card
 * Return: index
 */

int index_search(deck_node_t *card_1)
{
	int index;
	char *values = (char *)card_1->card->value;

	index = card_1->card->kind * 13;

	switch (values[0])
	{
		case 'A':
			index += 1;
			break;
		case '1':
			index += 10;
			break;
		case 'J':
			index += 11;
			break;
		case 'Q':
			index += 12;
			break;
		case 'K':
			index += 13;
			break;
		default:
			index += (values[0] - '0');
			break;
	}

	return (index);
}
/**
 * swap - that sorts a doubly linked list of integers
 * @list: doubly Pointers
 * @min: pointers with the value min
 * @max: Doubly Pointers the value
 */
void swap(deck_node_t **list, deck_node_t *min, deck_node_t **max)
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
}

/**
 * insertion_sort_list - that sorts a doubly linked list
 * @list: doubly Pointers
 */
void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *min, *max, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	for (min = (*list)->next; min; min = temp)
	{
		temp = min->next;
		max = min->prev;

		while (max && index_search(min) < index_search(max))
		{
			swap(list, min, &max);
		}
	}
}

/**
 *sort_deck - sort a deck of cards
 * @deck: unsorted deck
 *
 */

void sort_deck(deck_node_t **deck)
{
	if (!deck || !*deck || !(*deck)->next)
		return;
	insertion_sort_list(deck);
}
