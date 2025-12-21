#include "ft_printf.h"

int	ft_puthex(unsigned int n, char specifier)
{
	char	*base;
	int		count;

	count = 0;
	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, specifier);
	count += ft_putchar(base[n % 16]);
	return (count);
}
