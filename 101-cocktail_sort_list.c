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
				temp = current->next;
                if (current->prev)
                    current->prev->next = temp;
                if (temp->next)
                    temp->next->prev = current;
                current->next = temp->next;
                temp->prev = current->prev;
                current->prev = temp;
                temp->next = current;
                if (current == *list)
                    *list = temp;
                swapped = true;
                print_list(*list);
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
					temp = current->prev;
					if (temp->prev)
						temp->prev->next = current;
					if (current->next)
						current->next->prev = temp;
					temp->next = current->next;
					current->prev = temp->prev;
					temp->prev = current;
					current->next = temp;
					if (current == *list)
						*list = current;
					swapped = true;
					print_list(*list);
				}
				else
					current = current->prev;
			}
		}
		end = current->prev;
		start = current->next;
	}
}
