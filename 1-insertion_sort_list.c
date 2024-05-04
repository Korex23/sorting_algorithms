#include "sort.h"

/**
 * swap_two_nodes - This function swaps the position
 * of two given nodes in a DLL.
 * @n1: The first node
 * @n2: The second node
 * @list: Pointer to head of doubly linked list
 *
 */

void swap_two_nodes(listint_t *n1, listint_t *n2, listint_t **list)
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


/**
 * insertion_sort_list - This function sorts a doubly
 * linked list in ascending order, using the insertion sort algorithm.
 * @list: Pointer to head of doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp = NULL;

	if (!list)
		return;
	curr = *list;

	while (curr)
	{
		if (curr && curr->next && (curr->n > curr->next->n))
		{
			tmp = curr->next;
			swap_two_nodes(curr, curr->next, list);
			curr = tmp->prev ? tmp->prev : tmp;
			print_list(*list);

			while (tmp && tmp->prev && (tmp->n < tmp->prev->n))
			{
				swap_two_nodes(tmp->prev, tmp, list);
				print_list(*list);
			}
		}
		curr = curr->next;
	}
}
