/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:13:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 16:15:30 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

void	*reallocf(void *ptr, size_t size)
{
	(void)ptr;
	(void)size;
	ft_putstr("reaallocf() called\n");
	return (NULL);
}
