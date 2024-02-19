#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;
	int temp;

	for (interval = size / 3; interval >= 1; interval = (interval - 1) / 3)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= interval; j -= interval)
			{
				if (temp < array[j - interval])
					array[j] = array[j - interval];
				else
					break;
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
