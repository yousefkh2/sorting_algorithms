#ifndef SORT_H
#define SORT_H
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer
 * @prev: points to the previous node
 * @next: points to the next node
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
