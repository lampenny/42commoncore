#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	//start searching after null terminator to include it in search
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
		return (NULL);
}