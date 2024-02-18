#include "sort.h"
#include <time.h>

void quick_sort(int *array, size_t size);
void recursion_sort(int *array, int start, int last, int size);
int partition(int *array, int start, int last, int size);

/**
 * swap - swaps array index values
 *
 * @p: 1st index
 * @q: 2nd index
 */
void swap(int *p, int *q)
{
	int temp = *p;

	*p = *q;
	*q = temp;
}

/**
 * quick_sort - wwrapper function
 *
 * @array: pointer to array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{	
	/* will identify the upper and lower bound indices */
	recursion_sort(array, 0, size - 1, size);
	srand(time(NULL));
}

/**
 * recursion_sort - a recursion of the quick_sort algorithm
 * 
 * @array: pointer to array
 * @start: 1st index
 * @last: last index
 */
void recursion_sort(int *array, int start, int last, int size)
{
	if (start < last)
	{
		/* get pivot value */
		int pivot = partition(array, start, last, size);

		/* split into lower value list and high value lists from pivot */
		recursion_sort(array, start, pivot - 1, size);
		recursion_sort(array, pivot + 1, last, size);
	}
}

/**
 * partition - it will partition the list while sorting
 *
 * @array: pointer to array
 * @start: pointer to start value index
 * @last: pointer to last value index
 */
int partition(int *array, int start, int last, int size)
{
	int i, j, pivot_value, pivot_index;

	pivot_index = start + (rand() % (last - start));

	if (pivot_index != last)
		swap(&array[pivot_index], &array[last]);

	pivot_value = array[last];

	i = start;

	for (j = start; j < last; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
			print_array(array, size);
		}
	}
	swap(&array[i], &array[j]);
	return i;
}

int main()
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	quick_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}	
