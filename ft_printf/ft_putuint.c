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

	count = 0;
	if (nb >= 10)
		count += ft_putuint(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
