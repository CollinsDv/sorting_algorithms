#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, min_index;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
			if (min_index != i)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
