#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap_no = 0;

	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - 2); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_no++;
			}
		}
		if (swap_no > 0)
		{
			print_array(array, size);
			swap_no = 0;
		}
		else
			break;
	}
}
