#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *  using the Bubble sort algorithm
 *
 * @array: given array to be sorted
 * @size: array's size
 */
void bubble_sort(int *array, size_t size)
{
	int swap, temp;
	size_t i, size_copy;

	size_copy = size;
	if (size >= 2)
	{
		do {
			swap = 0;
			for (i = 1; i < size_copy; i++)
			{
				if (array[i - 1] > array[i])
				{
					temp = array[i - 1];
					array[i - 1] = array[i];
					array[i] = temp;
					swap = 1;
					print_array(array, size);
				}
			}
			size_copy -= 1;
		} while (swap);
	}
}
