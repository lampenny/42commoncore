#include <stdio.h>
#include <stdarg.h>

int   ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	char			buffer[17];
	char			*hex;
	int				i;
	int				count; 

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
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
int    is_valid_format(char c)
{
    return (c == 'p');
}

int    handle_format(char specifier, va_list *args)
{
	if (specifier == 'p')
		return (ft_putptr(va_arg(*args, void *)));
    return (0);
}

int    ft_printf(const char *format, ...)
{
    va_list        args;
    int            i;
    int            printed;

    printed = 0;
    i = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && is_valid_format(format[i + 1]))
        {
            i++;
            printed = handle_format(format[i], &args);
            printed++;
        }
        else
        {
            printed = ft_putchar(format[i]);
            printed++;
        }
        i++;
    }
    va_end(args);
    return (printed);
}

int    main(void)
{
	int n = 42;
	ft_printf("ma: %p \n", &n);

    return (0);
}