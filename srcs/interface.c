/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 13:25:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/22 17:34:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

t_chunk			*g_zones[M_ZONES_MAX] =
{
	NULL,
	NULL,
	NULL,
};
int				g_malloc_debug = 0;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void			*malloc(size_t size)
{
	void	*new_ptr;

	pthread_mutex_lock(&g_mutex);
	if (g_malloc_debug >= 1)
		DGS("malloc called");
	new_ptr = ft_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	return (new_ptr);
}

void			free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	if (g_malloc_debug >= 1)
		DGS("free called");
	ft_free(ptr);
	pthread_mutex_unlock(&g_mutex);
	return ;
}

void			*realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	pthread_mutex_lock(&g_mutex);
	if (g_malloc_debug >= 1)
		DGS("realloc called");
	new_ptr = ft_realloc(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (new_ptr);
}
