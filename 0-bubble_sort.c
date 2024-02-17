#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int temp, swap_no = 0;

	for (i; i < (size - 1); i++)
	{
		for (j; j < (size - 2); j++)
		{
			if array[j] > array[j + 1]
			{
				temp = array[j]
				array[j] = array[j + 1]
				array[j + 1] = temp
				swap_no++;
			}
		}
		if swap_no > 0
			print(array);
			swap_no = 0;
		else
			break;
	}
}
