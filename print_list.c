#include "sort.h"
#include <stdio.h>

/**
 * print_list - prints a doubly linked list of integers
 * @list: the list to be printed
 */
void print_list(const listint_t *list)
{
	while (list != NULL)
	{
		if (list->next != NULL)
			printf("%d, ", list->n);
		else
			printf("%d\n", list->n);
		list = list->next;
	}
}
