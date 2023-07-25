#include "sort.h"
#include <stdio.h>

void lomuto_sort(int *array, ssize_t low, ssize_t high, size_t size);
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}

/**
 * lomuto_sort - implements quick sort through Lomuto partition scheme
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the original array
 */
void lomuto_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		lomuto_sort(array, low, pivot - 1, size);
		lomuto_sort(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - partitions the array
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of the original array
 *
 * Return: the partition index
 */
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot, temp;
	ssize_t i, j;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
