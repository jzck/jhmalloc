/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:34:23 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 20:08:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

void	error_free_notalloc(void *ptr)
{
	int		fd;

	fd = 2;
	ft_putstr_fd(FG_RED"(", fd);
	ft_putnbr_fd(getpid(), fd);
	ft_putstr_fd(", ??? ", fd);
	ft_putstr_fd(")", fd);
	ft_putstr_fd(" malloc: error for object ", fd);
	ft_putnbr_hex_fd((long)ptr, fd);
	ft_putendl_fd(": pointer being freed was not allocated"FG_DEFAULT, fd);
	/* exit(134); */
}

void	error_mmap(void)
{
	int		fd;

	fd = 2;
	ft_putstr_fd(FG_RED"(", fd);
	ft_putnbr_fd(getpid(), fd);
	ft_putstr_fd(", ??? ", fd);
	ft_putstr_fd(")", fd);
	ft_putendl_fd(" malloc: mmap failed", fd);
	/* exit(134); */
}
