#include "sort.h"

void partition(int *arr, size_t size, size_t left, size_t right);
void swap(int *arr, size_t size, int *a, int *b);

/**
 * quick_sort - implement quick sort of elements in ascending order
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size);
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
	int pivot = arr[right]; /* set pivot value to last element */
	int i = left - 1;
	int j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return;

		swap(arr, size, &arr[i], &arr[j]);
	}

	/* lesser partition */
	partition(arr, size, left, j);
	/* greater partition */
	partition(arr, size, j + 1, right);
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
void swap(int *arr, size_t size, int *a, int *b)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;

		/* print update of the array */
		print_array(arr, size);
	}
}
