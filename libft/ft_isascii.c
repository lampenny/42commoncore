/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:10:30 by penlam            #+#    #+#             */
/*   Updated: 2025/10/26 16:20:08 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
int ascii;
ascii = 123;
printf("%d", ft_isascii(ascii));
   return (0);
}
*/
