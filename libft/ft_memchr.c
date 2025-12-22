/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:33:38 by penlam            #+#    #+#             */
/*   Updated: 2025/11/29 11:33:40 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*str;
	unsigned char			c2;
	size_t					i;

	c2 = (unsigned char) c;
	str = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c2)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}

/*
this function locates the first occurrence of 
c (converted to an unsigned char) in string s.

cast to void * to match the return type.
void * allows the caller to assign it to
whatever pointer type the need without casting.

returns a pointer to the byte
located or NULL if no such byte exists within
n bytes.
*/
