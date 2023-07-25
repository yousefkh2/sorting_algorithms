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

			if (swap_node->prev != NULL)
				swap_node->prev->next = temp;

			if (temp->next != NULL)
				temp->next->prev = swap_node;

			swap_node->next = temp->next;
			temp->prev = swap_node->prev;
			swap_node->prev = temp;
			temp->next = swap_node;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}
	}
}
