#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *input, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
// int		ft_putptr(unsigned long value, int asc);
// int		ft_putuint(unsigned int nb);
// int		ft_puthex(unsigned int value, int asc);

#endif
