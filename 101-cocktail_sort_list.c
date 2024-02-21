#include "sort.h"
/**
 * swapp - Swaps the node
 * @current: Pointer to current node
 * @curr_old: Pointer to old current
 * @list: pointer to list to use
 */
void swapp(listint_t *current, listint_t *curr_old, listint_t **list)
{
	listint_t *temp1 = current->next;
	listint_t *temp2 = curr_old->prev;

	if (temp1 != NULL)
		temp1->prev = curr_old;
	if (temp2 != NULL)
		temp2->next = current;
	current->prev = temp2;
	curr_old->next = temp1;
	current->next = curr_old;
	curr_old->prev = current;
	if (*list == curr_old)
		*list = current;
	print_list(*list);
}
/**
 * cocktail_sort_list - Sort integers in ascending
 * @list: The list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr = *list, *start = NULL, *end = NULL;
	int swapped;

	if (!list || !*list || !(*list)->next)
		return;
	do {
		swapped = 0;
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swapp(curr->next, curr, list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}
		end = curr;
		while (curr->prev != start)
		{
			if (curr->n < curr->prev->n)
			{
				swapp(curr, curr->prev, list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
		start = curr;
	} while (swapped && start != end);
}
