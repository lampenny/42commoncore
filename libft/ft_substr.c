#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(str);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (start >= str_len)
		return ((char *)malloc(1));
	if (len > str_len - start)
		len = str_len - start;
}
