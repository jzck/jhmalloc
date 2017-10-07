#include "../includes/malloc.h"

void	*ft_malloc(size_t size);
int		main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)ft_malloc(1024);
		addr[0] = 42;
		i++;
	}
	return (0);
}
