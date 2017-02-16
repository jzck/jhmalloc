#include "malloc.h"

t_node	*tiny_zone = NULL;
t_node	*small_zone = NULL;
t_node	*tiny_alloc = NULL;
t_node	*small_alloc = NULL;

t_node	**find_node(t_node **node, size_t size)
{
	while (*node && (size_t)(*node)->size < size + HEADER_SIZE)
		node = &(*node)->next;
	return (node);
}

void	add_chunk(t_node **node_ref, size_t size)
{
	size_t	chunk_size;

	while (*node_ref)
		node_ref = &(*node_ref)->next;
	chunk_size = TINY(size) ? malloc_N : malloc_M;
	printf("chunk_size=[%zu]\n", chunk_size);
	*node_ref = mmap(NULL, (chunk_size +1) * 8, PROT_READ|PROT_WRITE,
				MAP_ANON|MAP_PRIVATE, -1, 0);
	(*node_ref)->size = chunk_size;
	(*node_ref)->next = NULL;
}

void	*split_node(t_node **free, t_node **alloc, size_t size)
{
	t_node		*new_alloc;
	int			free_size;

	free_size = (*free)->size;
	/* printf("split now size=[%zu]\n", size); */
	/* printf("free @ [%p], size=[%i]\n", *free, (*free)->size); */
	/* printf("size = [%lu]\n", size + HEADER_SIZE); */
	/* printf("alloc @ [%p]\n", *alloc); */
	/* fflush(stdout); */
	new_alloc = *free;
	*(void**)free += 8 * (size + HEADER_SIZE);
	/* printf("free @ [%p], size=[%i]\n", *free, (*free)->size); */
	(*free)->size = free_size - (size + HEADER_SIZE);
	new_alloc->size = size;
	insert_node(alloc, new_alloc);
	return ((void*)new_alloc + HEADER_SIZE * 8);
}

void	*malloc(size_t size)
{
	t_node		**zone_ref;
	t_node		**alloc_ref;
	t_node		**node_ref;
	void		*ptr;

	printf("malloc(%zu) was called. [%lu] bytes\n", size, malloc_bytes(size));
	size = malloc_bytes(size);
	zone_ref = TINY(size) ? &tiny_zone : &small_zone;
	alloc_ref = TINY(size) ? &tiny_alloc : &small_alloc;
	while (!*(node_ref = find_node(zone_ref, size)))
		add_chunk(node_ref, size);
	ptr = split_node(node_ref, alloc_ref, size);
	return (ptr);
}
