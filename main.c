#include "includes/malloc.h"
#include <stdio.h>

int		main(void)
{
	void *ptr0 = malloc(8150);
	show_alloc_mem();
	printf("\n");

	void *ptr1 = malloc(300);
	show_alloc_mem();
	printf("\n");

	/* free(ptr0); */
	/* show_alloc_mem(); */
	/* printf("\n"); */

	free(ptr1);
	show_alloc_mem();
	printf("\n");

	return (0);
}
