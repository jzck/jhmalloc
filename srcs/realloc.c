/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:23:20 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:08:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

void	*ft_realloc(void *ptr, size_t size)
{
	if (ret_free(ptr))
		return (NULL);
	return (ft_malloc(size));
}
