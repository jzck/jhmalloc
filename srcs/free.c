/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/23 19:32:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"
#include <dlfcn.h>

int			g_malloc_debug;
t_chunk		*g_zones[M_ZONES_MAX];

int		coalesce_nodes(t_node *node)
{
	t_node	*next;

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

int		ft_free(void *ptr)
{
	t_node	*node;
	t_node	*prev;

	if (!ptr)
		return (2);
	if (g_malloc_debug >= 2)
		show_alloc_mem();
	node = ptr - M_NODEHEAD;
	if (!((prev = find_prev_node(g_zones[M_TINY], node))
				|| (prev = find_prev_node(g_zones[M_SMALL], node))
				|| (prev = find_prev_node(g_zones[M_LARGE], node))))
	{
		if (g_malloc_debug >= 2)
			error_free_notalloc(ptr);
		return (1);
	}
	node->isfree = 1;
	coalesce_nodes(prev);
	if (g_malloc_debug >= 2)
		show_alloc_mem();
	return (0);
}
