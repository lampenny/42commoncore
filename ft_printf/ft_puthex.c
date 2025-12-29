/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:03:40 by penlam            #+#    #+#             */
/*   Updated: 2025/12/29 15:23:50 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char specifier)
{
	char	*base;
	int		count;
	int		temp;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		temp = ft_puthex(n / 16, specifier);
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
