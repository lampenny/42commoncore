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

int	ft_printf(const char* str, ...)
{
	va_list	args;
	va_start(args, str);

	ft_putchar(args);
	return (0);
}

/*
args: the va_list to initialize.
str: the last fixed argument before the variable arguments (...)

*/
