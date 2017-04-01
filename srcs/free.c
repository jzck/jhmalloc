/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 12:04:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

int		coalesce_nodes(t_node *node)
{
	t_node	*next;

	if ((next = node->next) && next->isfree)
	{
		node->size += next->size;
		node->next = next->next;
	}
	return (0);
}

void	free(void *ptr)
{
	t_chunk	*zone;
	t_node	*node;
	t_node	*prev;

	/* DGSH("free   i", (int)ptr); */
	/* DGSH("free  ui", (unsigned int)ptr); */
	/* DGSH("free  ll", (long long)ptr); */
	DGSH("free ull", (unsigned long long)ptr);
	if (!ptr)
		return ;
	node = ptr - M_NODEHEAD;
	DGSN("node->size", node->size);
	zone = get_zone(node->size);
	DGSH("free", (long)ptr);
	if (!(prev = find_prev_node(zone, node)))
	{
		error_free_notalloc(ptr);
		return ;
	}
	DGSH("free", (long)ptr);
	coalesce_nodes(node);
	DGSH("free", (long)ptr);
	coalesce_nodes(prev);
	DGS("successful free");
}
