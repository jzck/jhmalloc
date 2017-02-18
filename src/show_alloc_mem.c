/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:20 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 19:58:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

t_node	*tiny_zone;
t_node	*small_zone;
t_node	*large_zone;
t_node	*tiny_alloc;
t_node	*small_alloc;
t_node	*large_alloc;

void	print_node(char color[7], t_node *node)
{
	ft_putstr("\t");
	ft_putstr(color);
	ft_putaddr(node->data);
	ft_putstr(" - ");
	ft_putaddr(node->data + node->size);
	ft_putstr(FBG_DEFAULT" : ");
	ft_putnbr(node->size);
	ft_putendl(" bytes");
}

void	show_alloc_zone(char *name, t_node *alloc, t_node *zone, size_t (*total)[3])
{
	if (alloc || zone)
		ft_putstr(name);
	while (alloc)
	{
		print_node(FG_RED, alloc);
		(*total)[1] += alloc->size;
		alloc = alloc->next;
	}
	while (zone)
	{
		print_node(FG_GREEN, zone);
		(*total)[0] += zone->size;
		zone = zone->next;
	}
}

void	show_alloc_mem(void)
{
	size_t	total[3];

	total[0] = 0;
	total[1] = 0;
	show_alloc_zone("TINY:", tiny_alloc, tiny_zone, &total);
	show_alloc_zone("SMALL:", small_alloc, small_zone, &total);
	show_alloc_zone("LARGE:", large_alloc, large_zone, &total);
	printf("Total:");
	printf("\t%7zu bytes free\n", total[0]);
	printf("\t%7zu bytes allocated\n", total[1]);
	printf("\t%7zu bytes mmap'd\n", total[0] + total[1]);
}
