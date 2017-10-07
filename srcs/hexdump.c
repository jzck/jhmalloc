/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:44:13 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 17:09:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

int			ft_dumpnbr_hex(char n)
{
	if (n < 0xa)
		ft_putchar('0');
	return (ft_putnbr_loop(n, 16, 1));
}

static void	print_hex_contents(void *addr, unsigned int size)
{
	void	*a;

	a = addr;
	while (a - addr < 16)
	{
		if ((a - addr) >= size)
			break ;
		else
			ft_dumpnbr_hex(*(unsigned char*)a);
		ft_putchar(' ');
		a++;
	}
}

void		*hexdump(void *addr, unsigned int offset, unsigned int size)
{
	void	*a;

	addr += offset;
	a = addr;
	if (addr == NULL)
		return (addr);
	while ((a - addr) < size)
	{
		print_hex_contents(a, (size - (a - addr)));
		ft_putchar('\n');
		a += 16;
	}
	return (addr);
}
