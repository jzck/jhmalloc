#ifndef MALLOC_H
# define MALLOC_H

#define malloc_n		20
#define malloc_m		100
#define malloc_N		100
#define malloc_M		500
#define malloc_magic	1234567
#define TINY(x)			(x < (malloc_n + 1))
#define SMALL(x)		(!TINY(x) && !LARGE(x))
#define LARGE(x)		(malloc_m < x)

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

extern t_node	*tiny_head;
extern t_node	*small_head;

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void show_alloc_mem(void);

#endif
