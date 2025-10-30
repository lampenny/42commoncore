/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:52:48 by penlam            #+#    #+#             */
/*   Updated: 2025/10/26 18:55:30 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
#include <stdio.h>
int main(void)
{

int a;
int b;
a = 'A';
b = 'b';
printf("%d \n", ft_tolower(a));
printf("%d", ft_tolower(b));

return 0;
}
*/
