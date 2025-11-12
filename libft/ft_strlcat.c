/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:31:07 by penlam            #+#    #+#             */
/*   Updated: 2025/11/07 10:03:01 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	i = 0;

	s_len = strlen(src);
	d_len = strlen(dst);
	// 3. overflow check 
	// If size is too small, return size + s_len
	if (d_len >= size)
		return  (size + s_len);

	// Copy what we can
	while (src[i] != '\0' && (d_len + i) < (size -1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
