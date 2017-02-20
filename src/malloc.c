/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:02 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/20 17:11:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

t_node	*tiny_zone;
t_node	*small_zone;
t_node	*large_zone;
t_node	*tiny_alloc;
t_node	*small_alloc;
t_node	*large_alloc;

void	add_chunk(t_node **zone_ref, size_t size)
{
	size_t	chunk_size;
	t_node	*node;

	/* while (*node_ref) */
	/* 	node_ref = &(*node_ref)->next; */
	if (LARGE(size))
		chunk_size = size + HEADER_SIZE;
	else
		chunk_size = TINY(size) ? malloc_N : malloc_M;
	if (!(node = mmap(NULL, chunk_size, PROT_READ|PROT_WRITE,
				MAP_ANON|MAP_PRIVATE, -1, 0)))
		error_mmap();
	ft_putstr("nchunk@");
	node->size = chunk_size;
	insert_node(zone_ref, node);
	print_node(BG_GREEN, node);
}

void	*malloc(size_t size)
{
	t_node	**zone_ref;
	t_node	**alloc_ref;
	t_node	**node_ref;
	t_node	*node;

	ft_putstr(FG_YELLOW"malloc(");
	ft_putnbr(size);
	ft_putendl(")"FG_DEFAULT);
	get_zones(&zone_ref, &alloc_ref, size);
	while (!*(node_ref = find_node_firstfit(zone_ref, size)))
		add_chunk(zone_ref, size);
	ft_putstr("found @");
	print_node(FG_GREEN, *node_ref);
	node = split_node(node_ref, alloc_ref, zone_ref, size);

	ft_putstr("touser@");
	print_node(FG_RED, node);
	ft_putstr(FG_YELLOW"passing ");
	ft_putnbr_hex((long)node->data);
	ft_putendl(" to user"FG_DEFAULT);
	return (node->data);
}
