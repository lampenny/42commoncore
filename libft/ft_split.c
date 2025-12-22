/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:34:28 by penlam            #+#    #+#             */
/*   Updated: 2025/11/29 11:34:30 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// first while skips leading delimiters
// second while counts chars until the next delimiter or end of string
static int	get_word(const char *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	while (s[*i + len] && s[*i + len] != c)
		len++;
	return (len);
}

static int	count_words(char const *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static void	*free_all(char **res, int words_allocated)
{
	int	i;

	i = 0;
	while (i < words_allocated)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	*allocate_word(char const *str, int start, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[start + len] && str[start + len] != c)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		len = get_word(s, c, &i);
		if (!s[i])
			break ;
		res[j] = allocate_word(s, i, c);
		if (!res[j])
			return (free_all(res, j));
		i += len;
		j++;
	}
	res[j] = NULL;
	return (res);
}
