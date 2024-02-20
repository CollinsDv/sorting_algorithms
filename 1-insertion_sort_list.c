#include "sort.h"
void swap(listint_t **a, listint_t **b);
/**
 * insertion_sort_list - sorts a list with the ascending order scheme
 * @list: head of list
 *
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *curr = NULL, *prev = NULL;
	 /* operate only when list has more than one element */
	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		temp = (*list)->next;

		while (temp) /* iterate to end of list */
		{
			curr = temp;
			prev = temp->prev;

			/* if values are not ascending */
			while (prev && curr->n < prev->n)
			{
				swap(&prev, &curr);
				if (prev == *list) /* if curr now list head */
					*list = curr;
				print_list(*list);
				/* if (curr->prev != NULL) if not at head of list */
				prev = curr->prev;
			}
			temp = temp->next;
		}
	}
}
/**
 * swap - swap two nodes addresses
 * @a: left node address
 * @b: right node address
 *
 * Return: None
 */
void swap(listint_t **a, listint_t **b)
{
	(*a)->next = (*b)->next;
	(*b)->prev = (*a)->prev;
	if ((*b)->next)
		(*b)->next->prev = (*a);
	if ((*a)->prev)
		(*a)->prev->next = (*b);
	(*b)->next = (*a);
	(*a)->prev = (*b);
}
