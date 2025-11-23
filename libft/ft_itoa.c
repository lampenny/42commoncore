#include "libft.h"
#include <limits.h>

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;
	size_t		len;
	bool		is_negative;
	long int	temp;
	int		i;
	
	if (n < 0)
		num = -(long int)n;
	else
		num = n;
	if (num == 0)
	{
		str = malloc(2 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	is_negative = (num < 0);
	if (is_negative)
		num = -num;
	len = 0;
	temp = num;
	while (temp > 0)
	{
		temp = temp / 10;
		len++;
	}
	if (is_negative)
		len++;
	len++;
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len - 1] = '\0';
	i = len - 2;
	while (num > 0)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
