#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *swap_node;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			swap_node = temp->prev;

			/* Swap the nodes */
			swap_node->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = swap_node;

			temp->prev = swap_node->prev;
			if (swap_node->prev != NULL)
				swap_node->prev->next = temp;

			temp->next = swap_node;
			swap_node->prev = temp;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}
	}
}
