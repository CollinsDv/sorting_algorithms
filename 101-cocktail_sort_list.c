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
		current = start;

		while (current && current->next != end->next)
		{
			if (current->n > current->next->n)
			{
				if (current == *list)
					*list = current->next;
				if (current->next == end)
					end = current;
				temp = current->next;
				current->next = temp->next;
				temp->next = current;
				swapped = true;
				print_list(list);
			}
			else
				current = current->next;
			
			if (!swapped)
				break;
			
			swapped = false;
			current = end;

			while (current != start)
			{
				if (current->n < current->prev->n)
				{
					if (current->prev == start)
						start = current;
					temp = current->prev;
					current->prev = temp->prev;
					temp->prev = current;
					temp->next = current->next;

					if (current->next != NULL)
						current->next->prev = temp;
					current->next = temp;
					swapped = true;
					print_list(list);
				}
				else
					current = current->prev;
			}
		}
		end = current->prev;
		start = current->next;
	}
}
