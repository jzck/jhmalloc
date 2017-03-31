/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 23:00:06 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/06 17:43:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

#include "stdlib.h"

# pragma GCC visibility push(default)

void	*calloc(size_t count, size_t size);
void	free(void *ptr);
void	*malloc(size_t size);
/* void	*realloc(void *ptr, size_t size); */
/* void	*reallocf(void *ptr, size_t size); */
/* void	*valloc(size_t size); */
void	show_alloc_mem(void);

# pragma GCC visibility pop

#endif
