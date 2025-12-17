/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:15:41 by penlam            #+#    #+#             */
/*   Updated: 2025/11/30 19:15:46 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	is_valid_format(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	handle_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(args));
	if (specifier == 's')
		return (ft_putstr(args));
	return (0);
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
		if (format[i] == '%' && is_valid_format(format[i + 1]))
		{
			i++;
			printed = handle_format(format[i], args);
			count += printed;
		}
		else
		{
			printed = ft_putchar(format[i]);
			count += printed;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	*str = "this is my string";

	ft_printf("my printf - char: %c\n", 'A');
	ft_printf("my printf - str: %s\n", str);
	return (0);
}