#include "malloc.h"

t_node	*tiny_zone;
t_node	*small_zone;

int		show_free_zone(t_node *node)
{
	int		total;

	total = 0;
	while (node)
	{
		printf("%p - %p: %i bytes\n", node, node + node->size, node->size);
		total += node->size;
		node = node->next;
	}
	return (total);
}

void	show_alloc_mem(void)
{
	int		total;

	total = 0;
	ft_putstr("TINY:\n");
	total += show_free_zone(tiny_zone);
	ft_putstr("SMALL:\n");
	total += show_free_zone(small_zone);
	printf("Total: %i bytes\n", total);
}
