#include "../includes/malloc.h"

int		main(void)
{
	ft_malloc(1024);
	ft_malloc(1024 * 32);
	ft_malloc(1024 * 1024);
	ft_malloc(1024 * 1024 * 16);
	ft_malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}
