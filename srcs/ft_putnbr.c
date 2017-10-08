/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:07:00 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/08 18:15:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

int	ft_putnbr_loop(long n, int base, int fd)
{
	if (n >= base)
		ft_putnbr_loop(n / base, base, fd);
	return (ft_putchar_fd("0123456789abcdef"[n % base], fd));
}

int	ft_putnbr_hex_fd(long n, int fd)
{
	ft_putstr_fd("0x", fd);
	return (ft_putnbr_loop(n, 16, fd));
}

int	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	n = FT_ABS(n);
	return (ft_putnbr_loop(n, 10, fd));
}

int	ft_putnbr_hex(long n)
{
	return (ft_putnbr_hex_fd(n, 1));
}

int	ft_putnbr(long n)
{
	return (ft_putnbr_fd(n, 1));
}
