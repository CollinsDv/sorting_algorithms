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
	int sort_no = 0, temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = i, j < size - 1, j++)
		{
			if array[i] < array[j]
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
				sort_no++;
			}
			if sort_no > 0
				sort_no = 0;
			else
				break;
		}
	}
}
