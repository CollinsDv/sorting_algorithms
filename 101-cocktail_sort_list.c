#include "sort.h"


/**
 * swap_nodes - Swaps the values of two nodes in a linked list.
 * @current: Pointer to the current node.
 * Return: void.
 */
void swap_nodes(listint_t *current)
{
	int temp;

	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
/**
 * swap_nodes_rev - Swaps the values of two nodes in a linked list in reverse order.
 * @current: Pointer to the current node.
 * Return: void.
 */
void swap_nodes_rev(listint_t *current)
{
	int temp;

	temp = current->n;
	current->n = current->prev->n;
	current->prev->n = temp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *
 * @list: The list to be printed
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = true;
	listint_t *start, *end, *current;

	if (*list == NULL || list == NULL)
		return;

	start = *list;
	end = *list;

	while(end->next != NULL)
		end = end->next;

	while (swapped && start != end)
	{
		current = start;
		swapped = false;
		while (current != end->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current);
				swapped = true;
				print_list(*list);
				current = current->next;
			}
		}
		if (!swapped)
			break;

		swapped = false;
		while (current != start->prev)
		{
			current = end;
			if (current->n < current->prev->n)
			{
				swap_nodes_rev(current);
				swapped = true;
				print_list(*list);
				current = current->prev;
			}
			if (!swapped)
				break;
			start = start->next;
			end = end->prev;
		}
	}
}
