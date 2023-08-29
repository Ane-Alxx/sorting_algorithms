#include "sort.h"
#include <stdio.h>

/**
*swap_node - function for swap node
*@node: a node
*@list: our array node
*Return: pointer to next, mark
*/

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *rev = node->prev, *mark = node;

	rev->next = mark->next;
	if (mark->next)
		mark->next->prev = rev;
	mark->next = rev;
	mark->prev = rev->prev;
	rev->prev = mark;
	if (mark->prev)
		mark->prev->next = mark;
	else
		*list = mark;
	return (mark);
}

/**
*cocktail_sort_list - function for cocktail_sort list
*@list: our list 
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int eng_game = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (end_game == 1)
	{
		end_game = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				end_game = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (end_game == 0)
			break;
		end_game = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				end_game = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
