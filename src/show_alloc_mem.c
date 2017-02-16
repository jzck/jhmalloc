#include "malloc.h"

t_node	*tiny_zone;
t_node	*small_zone;
t_node	*tiny_alloc;
t_node	*small_alloc;

void	print_free_mem(t_node *node)
{
	size_t	size;
	void	*addr;

	size = node->size;
	addr = (void*)node;
	printf("\t%p - %p : %4zu byte%c\n",
			addr, addr + 8 * size, size, size > 1 ? 's' : 0);
}

void	print_alloc_mem(t_node *node)
{
	size_t	size;
	void	*addr;

	size = node->size;
	addr = (void*)node + HEADER_SIZE;
	printf("\t%p - %p : %4zu(+%zu) byte%c\n",
			addr, addr + 8 * size, size, HEADER_SIZE, size > 1 ? 's' : 0);
}

int		show_zone(t_node *node, int is_free)
{
	int		total;

	total = 0;
	while (node)
	{
		is_free ? print_free_mem(node) : print_alloc_mem(node);
		total += node->size + HEADER_SIZE;
		node = node->next;
	}
	return (total);
}

void	show_alloc_mem(void)
{
	size_t	free_total;
	size_t	alloc_total;

	free_total = 0;
	alloc_total = 0;
	if (tiny_alloc)
		ft_putstr("TINY:");
	ft_putstr(FG_RED);
	alloc_total += show_zone(tiny_alloc, 0);
	ft_putstr(FG_GREEN);
	free_total += show_zone(tiny_zone, 1);
	ft_putstr(FG_DEFAULT);
	if (small_alloc)
		ft_putstr("SMALL:");
	ft_putstr(FG_RED);
	alloc_total += show_zone(small_alloc, 0);
	ft_putstr(FG_GREEN);
	free_total += show_zone(small_zone, 1);
	ft_putstr(FG_DEFAULT);
	printf("Total:");
	printf("\t%7zu bytes allocated\n", alloc_total);
	printf("\t%7zu bytes free\n", free_total);
	printf("\t%7zu bytes mapped\n", alloc_total + free_total);
}
