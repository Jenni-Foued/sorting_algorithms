#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *  in ascending order using the Insertion sort algorithm
 *
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *next_node;

	if (list == NULL || *list == NULL)
		return;
	current_node = (*list)->next;
	while (current_node)
	{
		next_node = current_node->next;
		while (current_node->prev && current_node->prev->n > current_node->n)
		{
			current_node->prev->next = current_node->next;
			if (current_node->next)
				current_node->next->prev = current_node->prev;
			current_node->next = current_node->prev;
			current_node->prev = current_node->next->prev;
			current_node->next->prev = current_node;
			if (current_node->prev)
				current_node->prev->next = current_node;
			else
				*list = current_node;
			print_list(*list);
		}
		current_node = next_node;
	}
}
