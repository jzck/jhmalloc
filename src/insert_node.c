#include "malloc.h"

void	insert_node(t_node **head, t_node *new)
{
	while (*head)
	{
		if (new < *head)
		{
			new->next = *head;
			*head = new;
			return ;
		}
		head = &(*head)->next;
	}
	*head = new;
}
