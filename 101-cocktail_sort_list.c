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
		for(current = start; current != end; current = current->next)
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
					*list = temp;
				current->prev = temp;
				temp->next = current;
				swapped = true;
				print_list(*list);
				printf("Forward pass done and swap done\n");
			}
			printf("Forward pass done\n");
		}
		if (!swapped)
			break;
		end = end->prev;
		swapped = false;
		printf("Swap is changed to false\n");
		for (current = end; current != start; current = current->prev)
		{
			if (current->prev && current->n < current->prev->n)
			{
				temp = current->prev;
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
				if (current->prev != NULL)
					current->prev->next = current;
				swapped = true;
				print_list(*list);
				printf("Backward pass done and swap done\n");
			}
		}
		printf("backward pass done\n");
		if (!swapped)
				break;
		start = start->next;
		printf("end of full pass\n");
	}
}
