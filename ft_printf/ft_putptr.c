/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:39:03 by penlam            #+#    #+#             */
/*   Updated: 2025/12/29 17:14:47 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex(unsigned long n)
{
	char	*base;
	int		count;
	int		temp;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		temp = put_hex(n / 16);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = ft_putchar(base[n % 16]);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	temp;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	temp = ft_putstr("0x");
	if (temp == -1)
		return (-1);
	count = temp;
	temp = put_hex((unsigned long)ptr);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}
