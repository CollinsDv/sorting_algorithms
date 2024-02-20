#include "sort.h"
#include "math.h"

void _copy(int *arr, int *temp, size_t size);

/**
 * merge_sort - an implementation of merge sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	/* temporary memory buffer */
	int *temp = malloc(sizeof(*temp) * size);

	if (temp == NULL)
	{
		printf("malloc failure\n");
		return;
	}

	/* ensure array has more than 1 element */	
	if (array && size > 1) 
		mergesort_recursion(array, 0, size - 1, temp);

	free(temp);
}

/**
 * mergesort_recursion - a recursion of merge_sort
 *
 * @array: array to sort
 * @l: left index
 * @r: right index
 * @temp: temporary buffer
 *
 * Return: void
 */
void mergesort_recursion(int *array, size_t l, size_t r, int *temp)
{
	size_t m;

	if (l >= r)
		return;

	/* midpoint */
	m = l + floor((r - l) / 2);

	/* split the array into sub-arrays */
	mergesort_recursion(array, l, m, temp);
	mergesort_recursion(array, m + 1, r, temp);

	/* compare and merge the adjusent nodes */
	merge(array, l, m, r, temp);
}

/**
 * merge - merges the subsequent sorted arrays from
 *         bottom up approach
 *
 * @array: array to merge
 * @l: left index of array / subarray
 * @m: middle index
 * @r: right index
 * @temp: temporary buffer
 *
 * Return: None
 */
void merge(int *array, size_t l, size_t m, size_t r, int *temp)
{
	size_t i_l = m, i_r = r, j = r - l;
	int l_merged = 0;

	printf("Merging...\n[left]: "); /* print sub-arrays */
	print_array(&array[l], (m + 1) - l);
	printf("[right]: ");
	print_array(&array[m + 1], (r + 1) - (m + 1));

	for (; i_l >= l && i_r >= m + 1;) /* compare individual elements */
	{
		if (array[i_r] >= array[i_l])
			temp[j--] = array[i_r--];
		else
		{
			temp[j--] = array[i_l];
			if (i_l == 0)
			{
				l_merged = 1;
				break;
			}
			i_l--;
		}
	}
	/* merges rest of whichever sub-array isn't fully merged */
	for (; i_r >= m + 1;)
		temp[j--] = array[i_r--];
	for (; !l_merged && i_l >= l;)
	{
		temp[j--] = array[i_l];
		if (i_l == 0) /* guards against size_t underflow */
			break;
		i_l--;
	}
	/* copy sorted temp back to original source array */
	_copy(&array[l], temp, (r + 1) - l);
	printf("[Done]: ");
	/* print sorted array */
	print_array(&array[l], (r + 1) - l);
}
/**
 * _copy - copy contents from temp array to source (same size)
 * @arr: copy destination
 * @temp: copy source
 * @size: size of arrays
 */
void _copy(int *arr, int *temp, size_t size)
{
	size_t i = 0;

	for (; i < size; i++)
		arr[i] = temp[i];
}
