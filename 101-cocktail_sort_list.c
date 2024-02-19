#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *
 * @list: The list to be printed
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = true;
	listint_t *start, *end, *current, *temp;

	if (*list == NULL || list == NULL)
		return;

	start = *list;
	end = *list;

	while(end->next != NULL)
		end = end->next;

	while (swapped)
	{
		swapped = false;
		for(current = start; current != NULL && current != end; current = current->next)
		{
			if (current->next && current->n > current->next->n)
			{
				temp = current->next;
				current->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = current;
				temp->prev = current->prev;
				if (current->prev != NULL)
					current->prev->next = temp;
				else
				{
					*list = temp;
					start = temp;
				}
				current->prev = temp;
				temp->next = current;
				swapped = true;
				print_list(*list);
			}
		}
		end = end->prev;
		swapped = false;
		for (current = end; current != NULL && current != start; current = current->prev)
		{
			if (current->prev && current->n < current->prev->n)
			{
				temp = current->prev;
				if (temp->prev != NULL)
				temp->prev->next = current;
				else
					*list = current;
				if (current->next != NULL)
					current->next->prev = temp;
				else
					end = temp;
				current->prev = temp->prev;
				temp->next = current->next;
				current->next = temp;
				temp->prev = current;
				swapped = true;
				print_list(*list);
			}
		}
		if (!swapped)
				break;
		start = start->next;
	}
}
