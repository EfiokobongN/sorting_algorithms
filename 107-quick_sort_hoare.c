#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: The first int.
 * @b: The second int.
 * Return: (void) Swaped integers.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Partition an array using pivot.
 * @array: The array to be partitioned.
 * @low: The low int.
 * @high: The high int.
 * @size: The size of array (size_t).
 * Return: The index of pivot (int).
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j = high;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}
/**
 * hoare_qsort - Sorting recursively of an array.
 * @array: The array to be sorted.
 * @low: The lowest value of the array.
 * @high: The highest value of the array.
 * @size: The size of the array.
 * Return: void.
 */
void hoare_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		if (i > low)
			hoare_qsort(array, low, i, size);
		hoare_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort_hoare - Quick sort algorithm using Hoare's partition.
 * @array: The array to sorted.
 * @size: Size of the array.
 * Return: Sorted array is modified in place (void).
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_qsort(array, 0, size - 1, size);
}
