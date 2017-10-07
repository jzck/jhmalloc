/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:07:04 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:07:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

int		ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}
