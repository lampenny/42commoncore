#include "libft.h"

void	ft_putendl_fd(char *d, int fd)
{
	int	i;

	i = 0;
	while (d[i])
	{
		write(fd, &d[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
