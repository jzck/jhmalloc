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

t_node	*tiny_zone;
t_node	*small_zone;
t_node	*large_zone;
t_node	*tiny_alloc;
t_node	*small_alloc;
t_node	*large_alloc;

int		coalesce_nodes(t_node **head)
{
	while (*head)
	{
		if ((*head)->next == *(void**)head + (*head)->size)
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
	t_node	*node;

	/* ft_putstr(FG_YELLOW"free("); */
	/* ft_putnbr_hex((long)ptr); */
	/* ft_putendl(")"FG_DEFAULT); */
	if (!ptr)
		return ;
	node = ptr - HEADER_SIZE;
	get_zones(&zone_ref, &alloc_ref, node->size);
	/* ft_putstr("zone  @"); */
	/* *zone_ref ? print_node(BG_MAGENTA, *zone_ref) : ft_putendl(" NULL"); */
	if (remove_node(alloc_ref, node))
	{
		/* error_free_notalloc(ptr); */
		return ;
	}
	insert_node(zone_ref, node);
	coalesce_nodes(zone_ref);
	/* ft_putendl(BG_GREEN"SUCCESSFUL FREE"BG_DEFAULT); */
}
