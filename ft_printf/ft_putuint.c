/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:03:23 by penlam            #+#    #+#             */
/*   Updated: 2025/12/22 11:03:25 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int nb)
{
	int	count;
	int	res;

	count = 0;
	if (nb >= 10)
		count += ft_putuint(nb / 10);
	res = ft_putchar((nb % 10) + '0');
	if (res == -1)
		return (-1);
	count += res;
	return (count);
}
