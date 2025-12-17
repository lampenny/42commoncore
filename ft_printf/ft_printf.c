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

#include "ft_printf.h"

int is_valid_format(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int handle_format(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(*args, char *)));
	// if (specifier == 'd' || specifier == 'i')
	// 	return (ft_putint(va_arg(*args, int)));
	// if (specifier == 'u')
	// 	return (ft_putuint(va_arg(*args, unsigned int)));
	// if (specifier == 'x' || specifier == 'X')
	// 	return (ft_puthex(va_arg(*args, unsigned int)));
	// if (specifier == 'p')
	// 	return (ft_putptr(va_arg(*args, void *)));
	// if (specifier == '%')
	// 	return ('%');
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	int i;
	int printed;

	printed = 0;
	i = 0;
	va_start(args, format);
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && is_valid_format(format[i + 1]))
		{
			i++;
			printed = handle_format(format[i], &args);
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