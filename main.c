#include "malloc.h"

int		main(void)
{
	printf("pagesize=[%i]\n", getpagesize());
	printf("sizeof(long)=[%lu]\n", sizeof(long));

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
