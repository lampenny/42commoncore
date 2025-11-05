/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:35:53 by penlam            #+#    #+#             */
/*   Updated: 2025/11/05 21:00:58 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/*
int main()
{
char str_1[] = "hello world";
char str_2[] = "hello";

char str_3[] = "goodbye world";
char str_4[] = "ABC";
char str_5[] = "abc";


printf("upcase and lowcase: %i \n", ft_strncmp(str_4, str_5, 1));

printf("upcase lowcase, real strncmp: %i \n", ft_strncmp(str_4, str_5, 1));

//printf("my strncmp, diff string: %i \n", ft_strncmp(str_1, str_2, strlen(str_1)));
//printf("standard strncmp, diff string: %i\n", strncmp(str_1, str_2, strlen(str_1)));


printf("my strncmp, same string:%i \n", ft_strncmp(str_2, str_3, strlen(str_2)));
printf("standard strncmp, same string: %i\n", strncmp(str_2, str_3, strlen(str_2)));
return (0);
}
