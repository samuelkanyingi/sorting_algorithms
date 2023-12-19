#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * @list: pointer to head of doubly linke dlist
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	curr = (*list)->next;
	while (curr)
	{
		tmp = curr->next;
		while (curr->prev && curr->n < curr->prev->n)
		{
			curr->prev->next = curr->next;
			if (curr->next)
				curr->next->prev = curr->prev;
			curr->next = curr->prev;
			curr->prev = curr->prev->prev;

			curr->next->prev = curr;
			if (curr->prev)
				curr->prev->next = curr;
			else
				*list = curr;
			print_list(*list);
		}
		curr = tmp;
	}
}
