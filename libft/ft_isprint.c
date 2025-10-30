/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:28:02 by penlam            #+#    #+#             */
/*   Updated: 2025/10/26 16:37:35 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
char c;
c = 'Z';

printf("printable %d \n", ft_isprint(c));

c = '\n';
printf("non printable %d \n", ft_isprint(c));
return 0;
}
*/
