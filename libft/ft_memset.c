/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:29:26 by penlam            #+#    #+#             */
/*   Updated: 2025/10/26 18:57:27 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ch;

	ch = s;
	while (n--)
		*ch++ = (unsigned char)c;
}
/*
#include <stdio.h>

int main()
{
	char str[50] = "Penny penny penny penny penny penny";
	printf("before ft_memset() %s\n", str);

	// Fill 6 characters starting from str[11] with '*'
	ft_memset(str + 11, '*', 6);

	printf("after ft_memset() %s \n", str);
	return (0);
}
*/
