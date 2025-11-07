/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:14:29 by penlam            #+#    #+#             */
/*   Updated: 2025/11/07 10:32:34 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>
char *ft_strnstr(const char *big, const char *little, size_t len)
{
// big is the haystack
// little is the needle
	int	i;
	const char *tracker[len];

	i = 0;
	while (big[i] != '\0' || len > 0)
	{
		if (big[i] == little[i])
			// append it to the tracker
			// tracker[i] = big[i];
			i++;
		else 
			i++;
	}
}

int main(){
const char *largestring = "Foo Bar Baz";
const char *smallstring = "Bar";
char *ptr;

ptr = strnstr(largestring, smallstring, 4);
    if (ptr)
        printf("Found substring: '%s'\n", ptr);
    else
        printf("Substring not found within first 4 characters. %s \n", ptr);
return (0);
}
