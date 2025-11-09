#include <stdio.h>
#include <stddef.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i--;
	
	if (s[i] == (unsigned char)c)
		return (char *)&s[i];
	else
		return NULL;
}