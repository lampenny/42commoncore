#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*str1;
	unsigned int	len;
	unsigned int	i;

	if (!str || !f)
		return (NULL);
	len = ft_strlen(str) + 1;
	str1 = malloc(len * sizeof(char));
	if (!str1)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		str1[i] = f(i, str[i]);
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
/*
return the string created from the successive applications of
'f'.
returns NULL if the allocation fails.
*/
