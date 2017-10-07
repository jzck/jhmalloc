#include "../includes/malloc.h"
#include <unistd.h>
#include <string.h>

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
	char	*addr;

	addr = ft_malloc(16);
	ft_free(NULL);
	ft_free((void*)addr + 5);
	if (ft_realloc((void*)addr + 5, 10) == NULL)
		print("Bonjours\n");
	return (0);
}
