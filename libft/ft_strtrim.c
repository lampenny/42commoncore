/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:33:18 by penlam            #+#    #+#             */
/*   Updated: 2025/11/29 11:33:21 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	copy_str(char *dest, const char *src, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		trim_len;
	char	*new_str;

	start = 0;
	while (s1[start] && is_in_set(set, s1[start]))
		start++;
	if (s1[start] == '\0')
	{
		new_str = malloc(1 * sizeof(char));
		if (new_str == NULL)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	end = ft_strlen(s1) - 1;
	while (end >= start && is_in_set(set, s1[end]))
		end--;
	trim_len = (end - start) + 1;
	new_str = malloc(trim_len + 1);
	if (new_str == NULL)
		return (NULL);
	copy_str(new_str, s1, start, trim_len);
	return (new_str);
}

/*
allocates memory and returns a 
copy of s1 with characters from set
removed from the beginning (Left side)
AND 
the end (Right side). Not the
middle.

set means to remove all char's
e.g all 'a's' and 'b's'
not remove substring set 'ab' 
*/
