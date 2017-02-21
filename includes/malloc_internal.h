/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 23:00:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 16:11:45 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_INTERNAL_H
# define MALLOC_INTERNAL_H

# define malloc_n			64
# define malloc_m			1024
# define malloc_N			(1 * getpagesize())
# define malloc_M			(2 * getpagesize())
# define malloc_magic		1234567
# define HEADER_SIZE		(sizeof(t_node) - alignof(t_node))
# define TINY(x)			(x < (malloc_n + 1))
# define SMALL(x)			(!TINY(x) && !LARGE(x))
# define LARGE(x)			(malloc_m < x)

#include "libft.h"
#include <sys/mman.h>
#include <stdalign.h>

typedef struct	s_header {
	int 		size;
	int 		magic;
}				t_header;

typedef struct		s_node {
	int				size;
	struct s_node	*next;
	char			data[1];
}					t_node;

extern t_node	*tiny_zone;
extern t_node	*small_zone;
extern t_node	*tiny_alloc;
extern t_node	*small_alloc;

#include "malloc.h"

void	get_zones(t_node ***zone_ref, t_node ***alloc_ref, size_t size);

void	insert_node(t_node **head, t_node *node);
int		remove_node(t_node **head, t_node *node);
t_node	*split_node(t_node **node, t_node **alloc, t_node **zone, size_t size);
t_node	**find_node_firstfit(t_node **node, size_t size);

void	show_free_mem(void);
void	print_node(char fg[7], t_node *node);

void	error_mmap(void);
void	error_free_notalloc(void *ptr);
#endif
