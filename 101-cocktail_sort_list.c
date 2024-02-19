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

	for (current = *list; current->next; current = current->next)
    	end = current;

	while (swapped)
	{
		swapped = false;
		for(current = start; current != NULL && current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				temp = current->next;
				if (current->prev)
					current->prev->next = temp;
				else
					*list = temp;
				if (temp->next)
					temp->next->prev = current;
				else
                    end = current;
				current->next = temp->next;
				temp->prev = current->prev;
				current->prev = temp;
				temp->next = current;
				swapped = true;
				print_list(*list);
			}
		}
		if (!swapped)
			break;
		swapped = false;
		for (current = end; current != NULL && current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				temp = current->prev;
				if (temp->prev)
					temp->prev->next = current;
				else
					*list = current;
				if (current->next)
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
		end = end->prev;
		start = start->next;
	}
}
