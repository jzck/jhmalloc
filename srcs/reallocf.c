/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 13:33:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/22 17:28:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

extern pthread_mutex_t	g_mutex;

void			*ft_reallocf(void *ptr, size_t size)
{
	void	*new_ptr;

	if (!(new_ptr = ft_realloc(ptr, size)))
		ft_free(ptr);
	return (new_ptr);
}
