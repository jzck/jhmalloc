/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 23:00:06 by jhalford          #+#    #+#             */
/*   Updated: 2017/10/07 16:25:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

#include "stdlib.h"

# pragma GCC visibility push(default)

void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	show_alloc_mem(void);
void	dump_alloc_mem(void);

/* void	*calloc(size_t count, size_t size); */
/* void	*reallocf(void *ptr, size_t size); */
/* void	*valloc(size_t size); */

# pragma GCC visibility pop

#endif
