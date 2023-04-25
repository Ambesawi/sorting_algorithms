#include "sort.h"

/**
 * swap - swap nodes one by one.
 * @a: first node-- beagining node.
 * @b: second node next node.
 * Return: nothing
 */
void swaping(listint_t *a, listint_t *b)
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
 * insertion_sort_list - perform insertion using insertion_sort_list.
 * @list: list to be sorted with insertion_sort_list.
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swaping(j->prev, j);
				if (j->prev == NULL)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
