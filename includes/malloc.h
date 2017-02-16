#ifndef MALLOC_H
# define MALLOC_H

# define malloc_n			64
# define malloc_m			512
# define malloc_N			(1 * getpagesize())
# define malloc_M			(2 * getpagesize())
# define malloc_magic		1234567
# define malloc_realign(x)	((((x) + 1) / 8) * 8)
# define malloc_bytes(x)	(((x) + 1) / 8)
# define HEADER_SIZE		malloc_bytes(sizeof(t_node))
# define TINY(x)			(x < (malloc_n + 1))
# define SMALL(x)			(!TINY(x) && !LARGE(x))
# define LARGE(x)			(malloc_m < x)

#include "../libft/includes/libft.h"
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

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	show_alloc_mem(void);
void	show_free_mem(void);
void	insert_node(t_node **head, t_node *new);

#endif
