/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:23:20 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 12:15:31 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

void	*realloc(void *ptr, size_t size)
{
	ft_putendl("realloc called");
	free(ptr);
	return (malloc(size));
}
