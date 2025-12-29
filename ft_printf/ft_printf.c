/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:15:41 by penlam            #+#    #+#             */
/*   Updated: 2025/12/29 16:52:25 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_format(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x'
		|| c == 'X');
}

int	handle_format(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_putuint(va_arg(*args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), specifier));
	if (specifier == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	return (0);
}

int	handle_print(const char *format, int *i, va_list *args)
{
	int	count;

	count = 0;
	if (format[*i] == '%' && format[*i + 1])
	{
		if (format[*i + 1] == '%')
			count = ft_putchar('%');
		else if (is_valid_format(format[*i + 1]))
			count = handle_format(format[*i + 1], args);
		else
		{
			count = ft_putchar(format[*i]);
			(*i)++;
			return (count);
		}
		*i += 2;
	}
	else
	{
		count = ft_putchar(format[*i]);
		(*i)++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		temp;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		temp = handle_print(format, &i, &args);
		if (temp == -1)
		{
			va_end(args);
			return (-1);
		}
		count += temp;
	}
	va_end(args);
	return (count);
}
