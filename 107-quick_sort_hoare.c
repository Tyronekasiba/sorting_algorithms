#include "sort.h"

/**
 * Hoare partition scheme - divides the array into two segments using the pivot element
 *
 * @arr: the array to be sorted
 * @low: starting index of the segment
 * @high: ending index of the segment
 * @size: size of the array
 *
 * Return: index of the pivot element for the next partition
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high], tmp;

	while (1)
	{
		while (arr[low] < pivot)
			low++;

		while (arr[high] > pivot)
			high--;

		if (low > high)
			return (high);

		tmp = arr[low];
		arr[low] = arr[high];
		arr[high] = tmp;

		if (low != high)
			print_array(arr, size);

		low++;
		high--;
	}
}

/**
 * Quick Sort - sorts an array by recursively dividing it into sub-arrays
 *
 * @array: the array to be sorted
 * @low: starting index of the segment
 * @high: ending index of the segment
 * @size: size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * Quick Sort with Hoare partition scheme - sorts an array using the Quick Sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

