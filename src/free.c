#include "malloc.h"

void	free(void *ptr)
{
	t_header *hptr;

	hptr = ptr - sizeof(t_header);
	ft_printf("hptr->magic = [%i]\n", hptr->magic);
}
