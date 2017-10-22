/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 14:35:06 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/22 18:44:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

int		g_malloc_debug;

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned long	big_size;

	big_size = count * size;
	if (!(ptr = ft_malloc(big_size)))
		return (ptr);
	ft_memset(ptr, 0, big_size);
	return (ptr);
}
