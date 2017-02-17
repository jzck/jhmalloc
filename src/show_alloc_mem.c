/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:20 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/17 23:13:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

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

void	show_alloc_zone(char *name, t_node *alloc, t_node *zone, size_t (*total)[3])
{
	if (alloc || zone)
		printf("%s", name);
	/* printf("%s", FG_RED); */
	ft_putstr(FG_RED);
	while (alloc)
	{
		print_alloc_mem(alloc);
		(*total)[1] += alloc->size;
		(*total)[2] += HEADER_SIZE;
		alloc = alloc->next;
	}
	printf("%s", FG_GREEN);
	while (zone)
	{
		print_free_mem(zone);
		(*total)[0] += zone->size;
		zone = zone->next;
	}
	printf("%s", FG_DEFAULT);
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
