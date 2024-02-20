#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *toInsert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		toInsert = current->prev;

		while (toInsert != NULL && current->n < toInsert->n)
		{
			current->prev = toInsert->prev;
			if (toInsert->prev != NULL)
				toInsert->prev->next = current;
			else
				*list = current;
			toInsert->prev = current;
			toInsert->next = current->next;
			if (current->next != NULL)
				current->next->prev = toInsert;
			current->next = toInsert;
			toInsert = current->prev;
			print_list((const listint_t *)*list);
		}
	}
}
