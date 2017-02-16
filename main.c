#include "malloc.h"

int		main(void)
{
	void	*ptr;

	printf("pagesize=[%i]\n", getpagesize());
	printf("sizeof(long)=[%lu]\n", sizeof(long));
	printf("sizeof(t_node)=[%lu]\n", sizeof(t_node));
	ptr = malloc(1 * sizeof(long));
	show_alloc_mem();
	ft_putchar('\n');

	ptr = malloc(84 * sizeof(long));
	show_alloc_mem();
	ft_putchar('\n');

	ptr = malloc(65 * sizeof(long));
	show_alloc_mem();
	ft_putchar('\n');

	ptr = malloc(64 * sizeof(long));
	show_alloc_mem();
	ft_putchar('\n');

	return (0);
}
