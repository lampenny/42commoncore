#include "ft_printf.h"

int	ft_putuint(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putuint(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
