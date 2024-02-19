#include "sort.h"



/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the doubly linked list.
 * @current:  Pointer to the first node to be swapped.
 * Return : void.
 */
void swap_nodes(listint_t **list, listint_t *current)
{
	listint_t *temp = current->next;

	current->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = current;
	temp->prev = current->prev;
	if (current->prev != NULL)
		current->prev->next = temp;
	else
		*list = temp;
	current->prev = temp;
	temp->next = current;
}

/**
 * Swaps the positions of two nodes in a doubly linked list in reverse order.
 *
 * @list: A pointer to the head of the doubly linked list.
 * @current: The first node to be swapped.
 * Return: void
 */
void swap_nodes_rev(listint_t **list, listint_t *current)
{
	listint_t *temp = current->prev;
	current->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = current;
	else
		*list = current;
	temp->next = current->next;
	if (current->next != NULL)
		current->next->prev = temp;
	current->next = temp;
	temp->prev = current;

	if (temp->prev != NULL)
		temp->prev->next = temp;
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

	while (swapped)
	{
		swapped = false;
		for(current = start; current != end; current = current->next)
		{
			if (current->next && current->n > current->next->n)
			{
				swap_nodes(list, current);
				swapped = true;
				print_list(*list);
			}
		}
		if (!swapped)
			break;

		swapped = false;
		for (current = end->prev; current != start; current = current->prev)
		{
			if (current->prev && current->n < current->prev->n)
			{
				swap_nodes_rev(list, current);
				swapped = true;
				print_list(*list);
			}
			if (!swapped)
				break;
			start = start->next;
			end = end->prev;
		}
	}
}
