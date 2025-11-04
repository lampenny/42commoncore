#include <stddef.h>
#include <stdio.h>
#include <string.h>
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] == (unsigned char)c)
		return (char *)&s[i];
	else
		return NULL;
}

int	main()
{
const char *test = "hello world";

printf("%s\n", ft_strchr(test, 'e'));
printf("Real strchr:    %s\n", strchr(test, 'e'));
return (0);
}
