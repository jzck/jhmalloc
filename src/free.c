#include "malloc.h"

int		remove_node(t_node **head, t_node *node)
{
	while (*head)
	{
		if (*head == node)
		{
			*head = (*head)->next;
			return (0);
		}
		head = &(*head)->next;
	}
	return (1);
}

int		coalesce_nodes(t_node **head)
{
	while (*head)
	{
		if ((*head)->next == *(void**)head + 8 * (*head)->size)
		{
			(*head)->size += (*head)->next->size;
			(*head)->next = (*head)->next->next;
		}
		else
			head = &(*head)->next;
	}
	return (0);
}

void	free(void *ptr)
{
	t_node	**zone_ref;
	t_node	**alloc_ref;
	t_node	*hptr;

	hptr = ptr - 8 * HEADER_SIZE;
	zone_ref = TINY(hptr->size) ? &tiny_zone : &small_zone;
	alloc_ref = TINY(hptr->size) ? &tiny_alloc : &small_alloc;
	/* printf("ptr @ [%p]\n", ptr); */
	/* printf("hptr @ [%p]\n", hptr); */
	/* printf("len=[%i]\n", hptr->size); */
	if (remove_node(alloc_ref, hptr))
		printf("trying to free bad address");
	insert_node(zone_ref, hptr);
	hptr->size += HEADER_SIZE;
	coalesce_nodes(zone_ref);
}
