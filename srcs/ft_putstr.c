/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:07:41 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/22 15:30:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		ft_putendl_fd(char const *s, int fd)
{
	char	nl;

	nl = '\n';
	write(fd, s, ft_strlen(s));
	return (write(fd, &nl, 1));
}

int		ft_putendl(char const *s)
{
	return (ft_putendl_fd(s, 1));
}

int		ft_putstr_fd(char const *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

int		ft_putstr(char const *s)
{
	return (write(1, s, ft_strlen(s)));
}
