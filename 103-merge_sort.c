#include "sort.h"

void merge(int *array, int *temp, size_t start, size_t mid, size_t end);
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end);
void merge_sort(int *array, size_t size);

/**
 * merge_sort - implementation of merge sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}

/**
 * merge_sort_recursive - a recursive to subsequent merge_sort calls
 *
 * @array: array/sub array to be merged
 * @temp: temp buffer
 * @start: start index
 * @end: end index
 */
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end)
{
	if (end - start > 1)
	{
		size_t mid = start + (end - start) / 2;

		merge_sort_recursive(array, temp, start, mid);
		merge_sort_recursive(array, temp, mid, end);
		merge(array, temp, start, mid, end);
	}
}

/**
 * merge - merges arrays in ascending order
 *
 * @array: array to merge
 * @temp: temporary buffer
 * @start: start index
 * @mid: midpoint
 * @end: endpoint
 *
 * Return: None
 */
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, end - mid);

	while (i < mid && j < end)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < end)
		temp[k++] = array[j++];

	for (i = start, k = 0; i < end; i++)
		array[i] = temp[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
