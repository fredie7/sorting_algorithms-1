#include "sort.h"

/**
 *insertion_sort_list - sort list using insertion algorithm
 *@list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *top, *prev, *next;

	if (!list || !(*list) || !(*list)->next)
		return;
	top = (*list)->next;
	while (top)
	{
		if (top->prev && top->prev->n > top->n)
		{
			while (top->prev)
			{
				prev = top->prev;
				if (top->prev && top->n < top->prev->n)
				{
					if (top->prev->prev)
						top->prev->prev->next = top;
					next = top->next;
					top->prev->next = next;
					if (next)
						next->prev = top->prev;
					top->next = prev;
					if (prev)
					{
						top->prev = prev->prev;
						prev->prev = top;
					}
					else
						top->prev = prev;
					if (!top->prev)
						*list = top;
					print_list(*list);
				}
				else
					break;
			}
		}
		top = top->next;
	}
}
