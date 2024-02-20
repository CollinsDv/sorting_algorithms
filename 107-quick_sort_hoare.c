#include "sort.h"

int partition(int *arr, size_t size, int left, int right);
void swap(int *a, int *b);
void hoare_sort(int *array, size_t size, int i, int j);
/**
 * quick_sort - implement quick sort of elements in ascending order
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	/* ensure the array has more than one element to sort */
	if (array && size > 1)
		hoare_sort(array, size, 0, size - 1);
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
int partition(int *arr, size_t size, int left, int right)
{
	int pivot, i, j;

	pivot = arr[right]; /* set pivot value to last element */
	for (i = left - 1, j = right + 1; i < j)
	{
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i < j)
		{
			swap(arr + i, arr + j);
			print_array(arr, size);
		}
	}
	return (i);
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
/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int i, int j)
{
	int part;

	if (j - i > 0)
	{
		part = partition(array, size, i, j);
		hoare_sort(array, size, i, part - 1);
		hoare_sort(array, size, part, j);
	}
}
