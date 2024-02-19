#include "sort.h"



/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the doubly linked list.
 * @current:  Pointer to the first node to be swapped.
 * @tail: Pointer to the last node in the list.
 * Return : void.
 */
void swap_nodes(listint_t **list, listint_t **current, listint_t **tail)
{
	listint_t *temp;

	temp = (*current)->next;
	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;
	(*current)->next = temp->next;
	temp->prev = (*current)->prev;
	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}

/**
 * Swaps the positions of two nodes in a doubly linked list in reverse order.
 *
 * @list: A pointer to the head of the doubly linked list.
 * @current: The first node to be swapped.
 * @tail: A pointer to the last node in the list.
 
 * Return: void
 */
void swap_nodes_rev(listint_t **list, listint_t **current, listint_t **tail)
{
	listint_t *temp;

	temp = (*current)->prev;
	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*current)->next;
	(*current)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = temp;
	temp->prev = current;
	*current = temp;
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
	listint_t *end, *current;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;
	
	for(end = *list; end->next != NULL;)
		end = end->next;
	
	while (swapped)
	{
		swapped = false;
		for(current = *list; current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &end, &current);
				print_list((const listint_t *)*list);
				swapped = true;
			
			}
		}
		if (!swapped)
			break;
		for (current = end->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes_rev(list, &end, &current);
				print_list((const listint_t *)*list);
			}
		}
	}
}