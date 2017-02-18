/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:53:41 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 20:06:53 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

t_node	*tiny_zone = NULL;
t_node	*small_zone = NULL;
t_node	*large_zone = NULL;
t_node	*tiny_alloc = NULL;
t_node	*small_alloc = NULL;
t_node	*large_alloc = NULL;

void	get_zones(t_node ***zone_ref, t_node ***alloc_ref, size_t size)
{
	if (LARGE(size))
	{
		*zone_ref = &large_zone;
		*alloc_ref = &large_alloc;
	}
	else
	{
		*zone_ref = TINY(size) ? &tiny_zone : &small_zone;
		*alloc_ref = TINY(size) ? &tiny_alloc : &small_alloc;
	}
	ft_putstr("zone  @");
	**zone_ref ? print_node(BG_MAGENTA, **zone_ref) : ft_putendl(" NULL");
}
