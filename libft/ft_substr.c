/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:35:02 by penlam            #+#    #+#             */
/*   Updated: 2025/11/29 11:35:06 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
if you don't assign storage for substr
it is just a pointer to garbage.

2 edge cases L12 and L14: 
L14 adjust the length if too long preventing users
from trying to copy more characters than actually exist.

L11 - L13
checks if the start is beyond the string.
 without this you access memory beyond the string.
by using ft_strdup (allocates memory for a new 
string, copies in to it with null terminator, returns pointer to new string)
L17 - this is checking if malloc failed. malloc doesnt always succeed: 
out of memory, memory fragmentation, system limits,k allocation too large.
*/
