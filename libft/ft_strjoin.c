#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str3;
	int		i;
	int		j;
	int		str1_len;
	int		str2_len;

	i = 0;
	j = 0;
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	str3 = malloc((str1_len + str2_len + 1) * sizeof(char));
	if (!str3)
		return (NULL);
	while (str1[i])
		str3[j++] = str1[i++];
	i = 0;
	while (str2[i])
		str3[j++] = str2[i++];
	str3[j] = '\0';
	return (str3);
}
