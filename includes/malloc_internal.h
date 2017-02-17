/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 23:00:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/17 23:25:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_INTERNAL_H
# define MALLOC_INTERNAL_H

# define malloc_n			64
# define malloc_m			1024
# define malloc_N			(1 * getpagesize())
# define malloc_M			(2 * getpagesize())
# define malloc_magic		1234567
# define HEADER_SIZE		(sizeof(t_node))
# define TINY(x)			(x < (malloc_n + 1))
# define SMALL(x)			(!TINY(x) && !LARGE(x))
# define LARGE(x)			(malloc_m < x)

#include "libft.h"
#include <sys/mman.h>

typedef struct	s_header {
	int 		size;
	int 		magic;
}				t_header;

typedef struct		s_node {
	int				size;
	struct s_node	*next;
}					t_node;

extern t_node	*tiny_zone;
extern t_node	*small_zone;
extern t_node	*tiny_alloc;
extern t_node	*small_alloc;

# pragma GCC visibility push(default)

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	show_alloc_mem(void);

# pragma GCC visibility pop

void	show_free_mem(void);
void	insert_node(t_node **head, t_node *new);

#endif
