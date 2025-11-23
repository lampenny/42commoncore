/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:00:02 by penlam            #+#    #+#             */
/*   Updated: 2025/10/30 21:25:36 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*chsrc;
	char		*chdest;
	size_t		i;

	i = 0;
	chsrc = (char *) src;
	chdest = (char *) dest;
	while (i < n)
	{
		chdest[i] = chsrc[i];
		i++;
	}
	return (dest);
}
