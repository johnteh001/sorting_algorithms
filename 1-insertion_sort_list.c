#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmpc;
	listint_t *tmpp, *tmp;

	if (!list || !(*list) || !((*list)->next))
		return;
	tmpc = (*list)->next;
	while (tmpc)
	{
		tmpp = tmpc->prev;
		tmp = tmpp;
		while (tmpp->n > tmpc->n)
		{
			tmpp->next = tmpc->next;
			tmpc->prev = tmpp->prev;
			if (tmpc->next)
				tmpc->next->prev = tmpp;
			if (tmpp->prev)
				tmpp->prev->next = tmpc;
			tmpc->next = tmpp;
			tmpp->prev = tmpc;
			if (tmpc->prev)
				tmpp = tmpc->prev;
			else
			{
				(*list) = tmpc;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		if (tmp->n > tmpc->n)
			tmpc = tmp->next;
		else if (tmp->next)
			tmpc = tmp->next->next;
		else
			tmpc = tmp->next;
	}
}
/**
 * print_list - Prints the elements of a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 */
void print_list(const listint_t *list)
{
	while (list)
	{
		printf("%d", list->n);
		if (list->next)
			printf(", ");
		list = list->next;
	}
	printf("\n");
}
