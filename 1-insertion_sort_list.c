#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *key = NULL;
	size_t list_len = 0;

	if (!list || !(*list) || !(temp->next))
		return;
	
	while (temp->next)
	{
		
	}
}
