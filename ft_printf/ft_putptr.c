#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	char			buffer[17];
	char			*hex;
	int				i;
	int				count;

	if (ptr == NULL)
		return (ft_putstr("0x0"));
	address = (unsigned long)ptr;
	i = 0;
	hex = "0123456789abcdef";
	while (address > 0)
	{
		buffer[i] = hex[address % 16];
		address = address / 16;
		i++;
	}
	count = ft_putstr("0x");
	while (i > 0)
	{
		i--;
		count += ft_putchar(buffer[i]);
	}
	return (count);
}
