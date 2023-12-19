#include "sort.h"
#include <stddef.h>

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recur(array, 0, size - 1, size);
}
/**
 *  quicksort_recur - reursive function to quick sort
 *  @array: array to sort
 *  @low_bound: lowerbound
 *  @high_bound: higher bound
 *  @size: array size
 */
void quicksort_recur(int *array, int low_bound, int high_bound, size_t size)
{
	if (low_bound < high_bound)
	{
		int pivot = lomuto_partition(array, low_bound, high_bound, size);
		 quicksort_recur(array, low_bound, pivot - 1, size);
		 quicksort_recur(array, pivot + 1, high_bound, size);
	}
}
/**
 * lomuto_partition - function to partition and find average number
 * @array: array size
 * @low_bound: lower bound
 * @high_bound: higher bound
 * @size: array size
 * Return: index of partition
 */
int lomuto_partition(int *array, int low_bound, int high_bound, size_t size)
{
	int pivot = array[high_bound];
	int i = low_bound - 1, j, temp;

	for (j = low_bound; j <= high_bound - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high_bound];
	array[high_bound] = temp;
	print_array(array, size);
	return (i + 1);
}
