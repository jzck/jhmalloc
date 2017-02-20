#include <stdlib.h>
#include "../includes/malloc.h"

int		main(void)
{
	void	*ptr0 = malloc(4096);
	show_alloc_mem();

	void	*ptr1 = malloc(16);
	show_alloc_mem();

	free(ptr0);
	show_alloc_mem();

	void	*ptr2 = malloc(16);
	show_alloc_mem();

	void	*ptr3 = malloc(32);
	show_alloc_mem();
}
