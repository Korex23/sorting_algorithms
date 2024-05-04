#include "sort.h"


void swap_nodes(listint_t *n1, listint_t *n2, listint_t **list);

/**
 * cocktail_sort_list - This function sorts a doubly
 * linked list in ascending order, using the  Cocktail shaker sort algorithm.
 * @list: Pointer to head of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int sorted = 1, swapped;

	if (!list || !*list || (*list)->next == NULL)
		return;

	while (sorted)
	{
		curr = *list;
		while (curr->next)
		{
			swapped = 0;
			if (curr->n > curr->next->n)
			{
				swap_nodes(curr, curr->next, list);
				print_list(*list);
				swapped = 1;
				sorted = 0;
			}
			if (!swapped)
				curr = curr->next;
		}

		if (sorted)
			break;
		sorted = 1;

		while (curr->prev)
		{
			swapped = 0;
			if (curr->n < curr->prev->n)
			{
				swap_nodes(curr->prev, curr, list);
				print_list(*list);
				swapped = 1;
				sorted = 0;
			}
			if (!swapped)
				curr = curr->prev;
		}

		if (sorted)
			break;
		sorted = 1;
	}
}

/**
 * swap_nodes - This function swaps the position
 * of two given nodes in a DLL.
 * @n1: The first node
 * @n2: The second node
 * @list: Pointer to head of doubly linked list
 */
void swap_nodes(listint_t *n1, listint_t *n2, listint_t **list)
{
	listint_t *tmp_node;

	if (n1 == NULL || n2 == NULL)
		return;
	tmp_node = n1->prev;

	if (tmp_node)
		tmp_node->next = n2;
	n2->prev = tmp_node;
	n1->next = n2->next;
	if (n2->next)
		n2->next->prev = n1;
	n2->next = n1;
	n1->prev = n2;

	if (!n2->prev)
		(*list) = n2;
}
