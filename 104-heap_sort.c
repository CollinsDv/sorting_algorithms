#include "sort.h"

/**
 * swap - swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * swap_and_print - Swaps two elements in an array and prints the array.
 *
 * @array: The array containing the elements.
 * @a: Pointer to the first element to be swapped.
 * @b: Pointer to the second element to be swapped.
 * @size: The size of the array.
 */
void swap_and_print(int *array, int *a, int *b, size_t size)
{
	swap(a, b);
	print_array(array, size);
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t end, root, child;

	if (array == NULL || size < 2)
		return;
	end = size - 1;
	for (root = (size - 1) / 2; ; root--)
	{
		while (root * 2 + 1 <= end)
		{
			child = root * 2 + 1;
			if (child < end && array[child] < array[child + 1])
				child++;
			if (array[root] < array[child])
			{
				swap_and_print(array, &array[end], &array[0], size);
				root = child;
			}
			else
				break;
		}
		if (root == 0)
			break;
	}
	while (end > 0)
	{
		swap_and_print(array, &array[end], &array[0], size);
		end--;
		root = 0;
		while (root * 2 + 1 <= end)
		{
			child = root * 2 + 1;
			if (child < end && array[child] < array[child + 1])
				child++;
			if (array[root] < array[child])
			{
				swap_and_print(array, &array[end], &array[0], size);
				root = child;
			}
			else
				break;
		}
	}
}
