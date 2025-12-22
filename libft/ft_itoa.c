/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:33:29 by penlam            #+#    #+#             */
/*   Updated: 2025/11/29 11:33:30 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static size_t	count_digits(long n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;
	size_t		len;
	int			is_negative;

	is_negative = (n < 0);
	if (n < 0)
		num = -(long int)n;
	else
		num = n;
	len = count_digits(num) + is_negative;
	str = malloc((len * sizeof(char)) + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
/*
special cases: 0, INT_MIN and negative.
ZERO: 0 is not negative so is_negative returns FALSE (0)
we account for that inside count_digits where it returns
1 immediately in the case of 0.

INT_MIN: we cast n to long to handle integer overflow.

NEGATIVES:
len = count_digits(num) + is_negative; <- we allocate
space for the negative sign here.
the last (is_negative) check adds the sign if it
is negative.
*/
