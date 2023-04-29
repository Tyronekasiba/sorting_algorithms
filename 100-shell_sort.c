#include "sort.h"

/**
 * sorting_with_gap - insertion sorting alogarithim
 * @array: the array to be sorted
 * @gap:the gap between values
 * @size: size of the @array
 */
void sort_with_gap(int *array, int gap, int size)
{
	int i = 0, j = 0, tmp;

	while (i + gap < size)
	{
		if (array[i] > array[i + gap])
		{
			j = i;
			while (j >= 0 && array[j] > array[j + gap])
			{
				tmp = array[j];
				array[j] = array[j + gap];
				array[j + gap] = tmp;
				j -= gap;
			}
		}
		i++;
	}
}

/**
 * knuth_sequence - Returns the number of the knuth sequence
 * @i: Index of the number
 * Return: the number at index @i of the knuth sequence
 */
size_t knuth_sequence(int i)
{
	size_t n = 1;

	while (i--)
		n = n * 3 + 1;
	return (n);
}
/**
 * shell_sort - implementation of the shell sort method
 * @array: array to sort
 * @size: the size of @array
 */
void shell_sort(int *array, size_t size)
{
	int i = 0;

	if (size < 2)
		return;

	while (knuth_sequence(i + 1) < size)
		i++;
	while (i >= 0)
	{
		sort_with_gap(array, knuth_sequence(i), size);
		print_array(array, size);
		i--;
	}
}
