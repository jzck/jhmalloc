#include "malloc.h"

int		main(void)
{
	void	*ptr;

	ptr = malloc(10);
	ptr = malloc(42);
	ptr = malloc(3);
	ptr = malloc(15);
	show_alloc_mem();
	return (0);
}
