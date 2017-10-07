/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 16:29:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

volatile int		g_malloc_debug;

int		coalesce_nodes(t_node *node)
{
	t_node	*next;

	show_alloc_mem();
	if (node->islast)
		return (0);
	next = (void*)node + node->size;
	if (node->isfree && next->isfree)
	{
		if (g_malloc_debug >= 2)
		{
			DGSH("coalescing 2 nodes at addr", (long)node);
			DGSH("and addr", (long)next);
		}
		node->islast = next->islast;
		node->size += next->size;
	}
	return (0);
}

int		ret_free(void *ptr)
{
	t_chunk	*zone;
	t_node	*node;
	t_node	*prev;

	if (!ptr)
		return (2);
	node = ptr - M_NODEHEAD;
	zone = *get_zone(node->size);
	if (!(prev = find_prev_node(zone, node)))
	{
		return (1);
	}
	node->isfree = 1;
	coalesce_nodes(prev);
	return (0);
}

void	ft_free(void *ptr)
{
	if (g_malloc_debug >= 1)
		DGSH("free called with addr", (long)ptr);
	if (g_malloc_debug >= 2)
		show_alloc_mem();
	if (ret_free(ptr) == 1)
		error_free_notalloc(ptr);
	if (g_malloc_debug >= 1)
		show_alloc_mem();
}
