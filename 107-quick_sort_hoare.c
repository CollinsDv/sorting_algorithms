#include "sort.h"

void partition(int *arr, size_t size, int left, int right);
void swap(int *a, int *b);

/**
 * quick_sort - implement quick sort of elements in ascending order
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	/* ensure the array has more than one element to sort */
	if (array && size > 1)
		partition(array, size, 0, size - 1);
}

/**
 * partition - sorts list according to a pivot value
 *
 * @arr: array
 * @size: array size
 * @left: leftmost element
 * @right: rightmost element
 *
 * Return: None
 */
void partition(int *arr, size_t size, int left, int right)
{
	int pivot, i, j;

	if (left >= right)
        return;
	pivot = arr[right]; /* set pivot value to last element */
	i = left - 1;
	j = right + 1;
	while (1)
	{
		do {
			i++;
		} while (i < right && arr[i] < pivot);

		do {
			j--;
		} while (j > left && arr[j] > pivot);

		if (i >= j)
		{
			/* lesser partition */
			if (j > left)
				partition(arr, size, left, j);
			/* greater partition */
			if (i < right)
				partition(arr, size, i + 1, right);
			return;
		}
		swap(&arr[i], &arr[j]);
		print_array(arr, size);
	}
}

/**
 * swap - swap value of indices in array
 *
 * @arr: array
 * @size: size of array
 * @a: pointer to index in array
 * @b: pointer to index in array
 *
 * Return: None
 */
void swap(int *a, int *b)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
