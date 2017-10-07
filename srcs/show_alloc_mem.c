/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:20 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:06:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

t_chunk		*g_zones[M_ZONES_MAX];

void	print_node(char color[7], t_node *node)
{
	ft_putstr("\t");
	ft_putstr(color);
	ft_putnbr_hex((long)(node));
	ft_putstr(" - ");
	ft_putnbr_hex((long)(node + 1));
	ft_putstr(" - ");
	ft_putnbr_hex((long)((void*)node + node->size));
	ft_putstr(FBG_DEFAULT" : ");
	ft_putnbr(node->size);
	ft_putstr(" bytes");
	ft_putchar('\n');
}

void	show_chunk(char *name, t_chunk *chunk, int dump)
{
	t_node	*node;

	ft_putstr(name);
	if (!chunk)
	{
		ft_putstr("empty");
		ft_putchar('\n');
		return ;
	}
	while (chunk)
	{
		ft_putchar('\n');
		node = (t_node*)(chunk + 1);
		while (node)
		{
			print_node(node->isfree ? FG_GREEN : FG_RED, node);
			if (dump && !node->isfree)
				hexdump(node, M_NODEHEAD, node->size - M_NODEHEAD);
			node = NEXT(node);
		}
		chunk = chunk->next;
	}
}

void	show_alloc_mem(void)
{
	show_chunk("TINY: ", g_zones[M_TINY], 0);
	show_chunk("SMALL: ", g_zones[M_SMALL], 0);
	show_chunk("LARGE: ", g_zones[M_LARGE], 0);
}

void	dump_alloc_mem(void)
{
	show_chunk("TINY: ", g_zones[M_TINY], 1);
	show_chunk("SMALL: ", g_zones[M_SMALL], 1);
	show_chunk("LARGE: ", g_zones[M_LARGE], 1);
}
