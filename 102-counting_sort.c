#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *count, *buffer;
	ssize_t h;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	/*finding largest element in the array*/
	for (h = 0; h < (ssize_t)size; h++)
	{
		if (max < array[h])
			max = array[h];
	}
	/*allocating memory to count array and initializing them to 0*/
	count = (int *)malloc((max + 1) * sizeof(int));
	buffer = malloc(size * sizeof(int));
	if (count == NULL || buffer == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	/*storing count of each element in the count array*/
	for (h = 0; h < (ssize_t)size; h++)
		count[array[h]]++;
	/*storing cumulative count in each of the elements*/
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	/*Print the counting array*/
	print_array(count, max + 1);
	/*copying into original array*/
	for (h = (ssize_t)size - 1; h >= 0; h--)
	{
		buffer[count[array[h]] - 1] = array[h];
		count[array[h]]--;
	}
	for (h = 0; h < (ssize_t)size; h++)
		array[h] = buffer[h];
	free(count);
	free(buffer);
}
