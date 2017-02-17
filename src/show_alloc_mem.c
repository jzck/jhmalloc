/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:20 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/17 13:18:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_node	*tiny_zone;
t_node	*small_zone;
t_node	*large_zone;
t_node	*tiny_alloc;
t_node	*small_alloc;
t_node	*large_alloc;

void	print_free_mem(t_node *node)
{
	size_t	size;
	void	*addr;

	size = node->size;
	addr = (void*)node;
	printf("\t%p - %p : %4zu byte%c\n",
			addr, (void*)addr + size, size, size > 1 ? 's' : 0);
}

void	print_alloc_mem(t_node *node)
{
	size_t	size;
	void	*addr;

	size = node->size;
	addr = (void*)node + HEADER_SIZE;
	printf("\t%p - %p : %4zu(+%zu) byte%c\n",
			addr, (void*)addr + size, size, HEADER_SIZE, size > 1 ? 's' : 0);
}

int		show_zone(t_node *node, int is_free, size_t (*total)[3])
{
	while (node)
	{
		is_free ? print_free_mem(node) : print_alloc_mem(node);
		(*total)[is_free ? 0 : 1] += node->size;
		(*total)[2] += is_free ? 0 : HEADER_SIZE;
		node = node->next;
	}
	return (0);
}

void	show_alloc_zone(char *name, t_node *alloc, t_node *zone, size_t (*total)[3])
{
	if (!alloc && !zone)
		return ;
	ft_putstr(name);
	ft_putstr(FG_RED);
	show_zone(alloc, 0, total);
	ft_putstr(FG_GREEN);
	show_zone(zone, 1, total);
	ft_putstr(FG_DEFAULT);
}

void	show_alloc_mem(void)
{
	size_t	total[3];

	total[0] = 0;
	total[1] = 0;
	total[2] = 0;
	show_alloc_zone("TINY:", tiny_alloc, tiny_zone, &total);
	show_alloc_zone("SMALL:", small_alloc, small_zone, &total);
	show_alloc_zone("LARGE:", large_alloc, large_zone, &total);
	printf("Total:");
	printf("\t%7zu bytes free\n", total[0]);
	printf("\t%7zu bytes allocated\n", total[1]);
	printf("\t%7zu header bytes\n", total[2]);
	printf("\t%7zu bytes mmap'd\n", total[0] + total[1] + total[2]);
}
