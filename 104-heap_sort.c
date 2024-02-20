#include "sort.h"



/**
 * Swaps the values of two elements in an array and updates the array.
 *
 * @array: The array containing the elements.
 * @root:The index of the first element to be swapped.
 * @child: The index of the second element to be swapped.
 * @size:The size of the array.
 * Return: void
 */
void swap_and_update(int *array, size_t root, size_t child, size_t size)
{
	int temp;

	temp = array[root];
	array[root] = array[child];
	array[child] = temp;

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
				swap_and_update(array, root, child, size);
			else
				break;
		}
		if (root == 0)
			break;
	}
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end--;
		root = 0;
		while (root * 2 + 1 <= end)
		{
			child = root * 2 + 1;
			if (child < end && array[child] < array[child + 1])
				child++;
			if (array[root] < array[child])
				swap_and_update(array, root, child, size);
			else
				break;
		}
	}
}
