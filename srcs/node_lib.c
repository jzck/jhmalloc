/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:15 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 12:04:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

t_node	*find_node_firstfit(t_chunk *chunk, size_t size)
{
	t_node	*node;

	if (!chunk)
		return (NULL);
	node = (t_node*)(chunk + 1);
	while (node && !(node->isfree && node->size >= size))
	{
		node = node->next;
	}
	return (node);
}

int		split_node(t_node *node, size_t size)
{
	t_node	*new_node;

	new_node = (void*)node + size;
	new_node->next = node->next;
	new_node->size = node->next - new_node;
	new_node->isfree = 1;
	node->next = new_node;
	node->size -= new_node->size;
	node->isfree = 0;
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
			n = n->next;
		}
		zone = zone->next;
	}
	return (NULL);
}
