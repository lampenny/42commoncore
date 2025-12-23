/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:03:33 by penlam            #+#    #+#             */
/*   Updated: 2025/12/22 11:03:34 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		len;
	int		res;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		nb = -nb;
	}
	if (nb > 9)
	{
		res = ft_putnbr(nb / 10);
		if (res == -1)
			return (-1);
		len += res;
	}
	if (ft_putchar((nb % 10) + '0') == -1)
		return (-1);
	len++;
	return (len);
}
