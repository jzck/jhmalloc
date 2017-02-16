#include "malloc.h"

t_node	*tiny_zone = NULL;
t_node	*small_zone = NULL;
t_node	*tiny_alloc = NULL;
t_node	*small_alloc = NULL;

t_node	**find_node(t_node **node, size_t size)
{
	while (*node && (size_t)(*node)->size < sizeof(t_header) + size)
		node = &(*node)->next;
	return (node);
}

void	add_chunk(t_node **node_ref, size_t size)
{
	while (*node_ref)
		node_ref = &(*node_ref)->next;
	*node_ref = mmap(NULL, malloc_N, PROT_READ|PROT_WRITE,
				MAP_ANON|MAP_PRIVATE, -1, 0);
	(*node_ref)->size = (TINY(size) ? malloc_N : malloc_M) + sizeof(t_node);
	(*node_ref)->next = NULL;
}

void	*split_node(t_node **node, size_t size)
{
	t_header	*hptr;
	int			free_size;

	free_size = (*node)->size;
	hptr = *(t_header**)node;
	*node = *node + size + sizeof(*hptr);
	(*node)->size = free_size - size - sizeof(*hptr);
	hptr->size = size;
	hptr->magic = malloc_magic;
	return (hptr + sizeof(*hptr));
}

void	*malloc(size_t size)
{
	t_node		**zone_ref;
	t_node		**node_ref;
	void		*ptr;

	printf("malloc(%zu) was called\n", size);
	zone_ref = TINY(size) ? &tiny_zone : &small_zone;
	while (!(*(node_ref = find_node(zone_ref, size))))
		add_chunk(node_ref, size);
	ptr = split_node(node_ref, size);
	return (ptr);
}
