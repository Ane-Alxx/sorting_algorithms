#include "sort.h"
/**
* insertion_sort_list - functiom for actual insertion sort
* @list: list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *noodle;

	if (list == NULL || (*list)->next == NULL)
		return;
	noodle = (*list)->next;
	while (noodle)
	{
		while ((noodle->prev) && (noodle->prev->n > noodle->n))
		{
			noodle = swap_node(noodle, list);
			print_list(*list);
		}
		noodle = noodle->next;
	}
}
/**
*swap_node - function for swapping nodes not noodles
*@node: our noodle node
*@list: the list of nodes; nooodle string
*Return: something
*/
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *trace = node->prev, *current = node;

	trace->next = current->next;
	if (current->next)
		current->next->prev = trace;
	current->next = trace;
	current->prev = trace->prev;
	trace->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
