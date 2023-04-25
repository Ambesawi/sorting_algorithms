#include "sort.h"

/**
 * swap_l - swap nodes for exchange
 * @a: first node that is to be swaped.
 * @b: second node that is to be swapped.
 * Return: nothing
 */
void swap_l(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
/**
 * cocktail_sort_list - perform sorting using cocktail_sort_list.
 * @list: list to be sorted in cocktail_sort_list.
 * Return: nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current_t;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_t = *list;
	while (swapped)
	{
		swapped = 0;
		while (current_t && current_t->next)
		{
			if (current_t->n > current_t->next->n)
			{
				swap_l(current_t, current_t->next);
				if (current_t->prev->prev == NULL)
					*list = current_t->prev;
				print_list(*list);
				swapped = 1;
			}
			else
				current_t = current_t->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (current_t && current_t->prev)
		{
			if (current_t->n < current_t->prev->n)
			{
				swap_l(current_t->prev, current_t);
				if (current_t->prev == NULL)
					*list = current_t;
				print_list(*list);
				swapped = 1;
			}
			else
				current_t = current_t->prev;
		}
	}
}
