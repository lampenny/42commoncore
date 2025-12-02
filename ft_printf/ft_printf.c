#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int	count;
	int	i;
	int	printed;

	printed = 0;
	i = 0;
	va_start(args, format);
	count = 0;
	while (format[i])
	{
		if (format[i] != '%' && format[i + 1] != 'c')
		{
			printed = ft_putchar(format[i]);
			count += printed;
			i = i + 1;
		} 
		else
		{
			printed = ft_putchar(va_arg(args, int));
			count += printed;
			i = i + 2;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	test1;
	int	test2;

	test1 = ft_printf("char: %c\n", 'A');
	test2 = printf("char: %c\n", 'A');
	printf("my ft_printf: %d\n", test1);
	printf("printf: %d\n", test2);

	return (0);
}
