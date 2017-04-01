/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 23:00:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 12:03:35 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_INTERNAL_H
# define MALLOC_INTERNAL_H

# define M_NTINY			(64)
# define M_NSMALL			(1024)
# define M_PAGEALIGN(x)		((x / getpagesize() + 1) * getpagesize())
# define M_TINYCHUNK		(M_PAGEALIGN(101 * M_NTINY))
# define M_SMALLCHUNK		(M_PAGEALIGN(101 * M_NSMALL))
# define M_MAGIC			1234567
# define M_CHUNKHEAD		(sizeof(t_chunk) - alignof(t_chunk))
# define M_NODEHEAD			(sizeof(t_node) - alignof(t_node))
# define M_ISTINY(x)		(x < (M_NTINY + 1))
# define M_ISSMALL(x)		(!M_TINY(x) && !M_LARGE(x))
# define M_ISLARGE(x)		(M_SMALL < x)

#include "libft.h"
#include <sys/mman.h>
#include <stdalign.h>

typedef struct		s_chunk {
	struct s_chunk	*next;
}					t_chunk;

typedef struct		s_node {
	struct s_node	*next;
	size_t			size;
	int				isfree:1;
}					t_node;

enum				e_zones {
	M_TINY,
	M_SMALL,
	M_LARGE,
	M_ZONES_MAX,
};

extern t_chunk	*g_zones[M_ZONES_MAX];

#include "malloc.h"

t_chunk		*get_zone(size_t size);
t_node		*find_node_firstfit(t_chunk *chunk, size_t size);
t_node		*find_prev_node(t_chunk *zone, t_node *node);
int			split_node(t_node *node, size_t size);

void	show_free_mem(void);
void	print_node(char fg[7], t_node *node);

void	error_mmap(void);
void	error_free_notalloc(void *ptr);
#endif
