/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:15 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:09:11 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

t_node	*find_node_firstfit(t_chunk *chunk, size_t size)
{
	t_node	*node;

	if (!chunk)
		return (NULL);
	node = (t_node*)(chunk + 1);
	while (node)
	{
		if (node->isfree && node->size >= size)
			break ;
		node = NEXT(node);
	}
	return (node);
}

int		split_node(t_node *node, size_t size)
{
	t_node	*new_node;

	node->isfree = 0;
	if (node->size - size <= M_NODEHEAD)
		return (0);
	new_node = (void*)node + size;
	new_node->size = node->size - size;
	new_node->isfree = 1;
	new_node->islast = node->islast;
	node->islast = 0;
	node->size = size;
	return (0);
}

t_node	*find_prev_node(t_chunk *zone, t_node *node)
{
	t_node	*n;
	t_node	*prev;

	while (zone)
	{
		n = (t_node*)(zone + 1);
		prev = n;
		while (n)
		{
			if (n == node)
				return (prev);
			prev = n;
			n = NEXT(n);
		}
		zone = zone->next;
	}
	return (NULL);
}
