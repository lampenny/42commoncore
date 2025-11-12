/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:53:29 by penlam            #+#    #+#             */
/*   Updated: 2025/11/05 17:58:44 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// finds the first occurrence of a character in a string
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		//checks everything before the null terminator
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	//Checks only the null terminator itself
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}