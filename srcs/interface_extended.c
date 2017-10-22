/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_extended.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:32:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/22 18:45:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

t_chunk			*g_zones[M_ZONES_MAX];
int				g_malloc_debug;
pthread_mutex_t	g_mutex;

void			*reallocf(void *ptr, size_t size)
{
	void	*new_ptr;

	pthread_mutex_lock(&g_mutex);
	if (g_malloc_debug >= 1)
		DGS("reallocf called");
	new_ptr = ft_reallocf(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (new_ptr);
}

void			*calloc(size_t count, size_t size)
{
	void	*new_ptr;

	pthread_mutex_lock(&g_mutex);
	if (g_malloc_debug >= 1)
		DGS("calloc called");
	new_ptr = ft_calloc(count, size);
	pthread_mutex_unlock(&g_mutex);
	return (new_ptr);
}

void			show_alloc_mem(void)
{
	pthread_mutex_lock(&g_mutex);
	show_chunk("TINY: ", g_zones[M_TINY], 0);
	show_chunk("SMALL: ", g_zones[M_SMALL], 0);
	show_chunk("LARGE: ", g_zones[M_LARGE], 0);
	pthread_mutex_unlock(&g_mutex);
}

void			dump_alloc_mem(void)
{
	pthread_mutex_lock(&g_mutex);
	show_chunk("TINY: ", g_zones[M_TINY], 1);
	show_chunk("SMALL: ", g_zones[M_SMALL], 1);
	show_chunk("LARGE: ", g_zones[M_LARGE], 1);
	pthread_mutex_unlock(&g_mutex);
}
