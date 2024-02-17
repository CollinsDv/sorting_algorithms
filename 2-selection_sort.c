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
		sort_no = 0;
		for (j = i + 1, j < size; j++)
		{
			if (array[j] < array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
				sort_no++;
			}
			if (sort_no == 0)
				break;
		}
	}
}
