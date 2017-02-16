#include "malloc.h"

int		main(void)
{
	printf("pagesize=[%i]\n", getpagesize());
	printf("sizeof(long)=[%lu]\n", sizeof(long));
	printf("sizeof(t_node)=[%lu]\n", sizeof(t_node));

	void *ptr0 = malloc(16 * sizeof(long));
	show_alloc_mem();
	printf("\n");

	void *ptr1 = malloc(32 * sizeof(long));
	show_alloc_mem();
	printf("\n");

	/* void *ptr2 = malloc(64 * sizeof(long)); */
	/* show_alloc_mem(); */
	/* printf("\n"); */

	/* void *ptr3 = malloc(20 * sizeof(long)); */
	/* show_alloc_mem(); */
	/* printf("\n"); */

	free(ptr0);
	show_alloc_mem();
	printf("\n");

	free(ptr1);
	show_alloc_mem();
	printf("\n");

	/* free(ptr2); */
	/* show_alloc_mem(); */
	/* printf("\n"); */

	return (0);
}
