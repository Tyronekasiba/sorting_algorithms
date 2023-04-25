#include "sort.h"

/**
 * insertion_sort_list - Sorting a doubly linked list of
 * integers in ascending order using  Insertion sorting algorithm
 *
 * Args:
 *	@list: double pointer to the head node of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;
	while (cur != NULL)
	{
		tmp = cur;
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;
			print_list(*list);
		}
		cur = cur->next;
	}
}
