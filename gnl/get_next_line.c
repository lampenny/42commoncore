#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[1];
	int	i;
	int	bytes_read;

	if (fd < 0)
		return (NULL);
	line = (char *)malloc(11 * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < 10 && (bytes_read = read(fd, buffer, 1)) > 0)
	{	
		if (buffer[0] == '\n')
		{
			line[i] = buffer[0];
			i++;
			break;
		}
		line[i] = buffer[0];
		i++;
	}
	if (bytes_read <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}
