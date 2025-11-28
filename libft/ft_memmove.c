/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:02:24 by penlam            #+#    #+#             */
/*   Updated: 2025/11/16 17:03:55 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr > src_ptr)
		while (len--)
			dest_ptr[len] = src_ptr[len];
	else
		while (len--)
			*dest_ptr++ = *src_ptr++;
	return (dest);
}

/*
returns the original val of dest.
the function copies len byes from src
to dest. the two strings may overlap;
the copy is always done in a nondestructive
manner which means not in place.
*/
