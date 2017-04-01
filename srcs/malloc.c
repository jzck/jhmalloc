/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:02 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 12:15:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

void	add_chunk(t_chunk **chunk, size_t size)
{
	int		chunk_size;
	t_chunk	*new;
	t_node	*node;

	if (M_ISLARGE(size))
		chunk_size = M_PAGEALIGN(size);
	else
		chunk_size = M_ISTINY(size) ? M_TINYCHUNK : M_SMALLCHUNK;
	if (!(new = mmap(NULL, chunk_size, PROT_READ|PROT_WRITE,
					MAP_ANON|MAP_PRIVATE, -1, 0)))
		error_mmap();
	new->next = *chunk;
	*chunk = new;
	node = (t_node*)(*chunk + 1);
	node->size = chunk_size - M_CHUNKHEAD;
	node->next = 0;
	node->isfree = 1;
}

void	*malloc(size_t size)
{
	t_chunk	*zone;
	t_node	*node;
	void	*ret;

	DGSN("malloc", size);
	size += M_NODEHEAD;
	zone = get_zone(size);
	DGSH("zone", (long)zone);
	while (!(node = find_node_firstfit(zone, size)))
		add_chunk(&zone, size);
	split_node(node, size);
	ret = (void*)node + M_NODEHEAD;
	DGSH("to user", (long)ret);
	return (ret);
}
