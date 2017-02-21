/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:13:00 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 16:16:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

void	*calloc(size_t count, size_t size)
{
	(void)count;
	(void)size;
	ft_putstr("calloc() called\n");
	return (NULL);
}
