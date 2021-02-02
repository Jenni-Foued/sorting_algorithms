#include "sort.h"

/**
 * partition - This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot
 *
 * @array: array to be sorted
 * @low: lowest index of the array's partition
 * @high: highest index of the array's partition
 * @size: size of the array
 *
 * Return: partion's index
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot, temp;
	size_t i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
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

/**
 * quickSort - sort an array partition by partition
 *
 * @array: array to be sorted
 * @low: lowest index of the partition of the array to sort
 * @high: highest index of the partition of the array to sort
 * @size: size of array
 */
void quickSort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quickSort(array, low, pivot - 1, size);
		quickSort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *  using the Quick sort algorithm
 *
 * @array: array to be sorted
 * @size: array'size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
