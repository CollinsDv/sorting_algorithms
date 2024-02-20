#include "sort.h"


/**
 * Swaps the values of two integers and updates the root pointer.
 *
 * This function swaps the values of two integers pointed to by `a` and `b`.
 * It also updates the root pointer to point to the new value of `b`.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * @root: Pointer to the root pointer.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * Return: void.
 */
void swap_and_update(int *a, int *b, int **root, int *array, size_t size)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    print_array(array, size);
    *root = b;
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
				swap_and_update(root, child, &root, array, size);
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
				swap_and_update(root, child, &root, array, size);
			else
				break;
		}
	}
}
