#include "sort.h"

/**
 * swap_ints - Swapping two integers in an array
 * Args:
 *	@a: Pointer to first integer
 *	@b: Pointer to second integer
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * partition - Partitions an array using the Lomuto scheme
 * Args:
 *	@array: Pointer to the array
 *	@low: Starting index of the partition to sort
 *	@high: Ending index of the partition to sort
 *	@size: Size of the array
 *
 * Return: Index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;

    int j;
    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap_ints(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if (i + 1 != high)
    {
        swap_ints(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quicksort - Sorting a partition of an array with Lomuto scheme
 * Args:
 *	@array: Pointer to the array
 *	@low: Starting index of the partition to be sorted
 *	@high: Ending index of the partition to be sorted
 *	@size: Size of the array to be sorted
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = partition(array, low, high, size);
        quicksort(array, low, pivot - 1, size);
        quicksort(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorting an integer array using Quick sort algorithm
 * Args:
 *	@array: Pointer to the array to be sorted
 *	@size: Size of the array being sorted
 */
void quick_sort(int *array, size_t size)
{
    if (array && size > 1)
        quicksort(array, 0, size - 1, size);
}
