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

t_chunk		*g_zones[M_ZONES_MAX] =
{
	NULL,
	NULL,
	NULL,
};

t_chunk		*get_zone(size_t size)
{
	if (M_ISLARGE(size))
		return (g_zones[M_LARGE]);
	else
		return (g_zones[M_ISTINY(size) ? M_TINY : M_SMALL]);
}
