/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:59:25 by penlam            #+#    #+#             */
/*   Updated: 2025/10/30 21:22:00 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = 10 * result + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main()
{
int val;
char *str;
str = "1509.10E";
val = ft_atoi(str);
printf("val = %d\n", val); // expected output: 1509

 str = "-9885";
val = ft_atoi(str);

printf("val = %d\n", val); // expected output: -9885
str = "       -1234ab567";
val = ft_atoi(str);

printf("val (expected output -1234 = %d\n", val); // expected output: -1234
return (0);
}
*/
