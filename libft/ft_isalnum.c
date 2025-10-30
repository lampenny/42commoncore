/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:57:59 by penlam            #+#    #+#             */
/*   Updated: 2025/10/26 16:24:46 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
    printf("Test 'A': %d\n", isalnum('A'));  // uppercase
    printf("Test 'z': %d\n", isalnum('z'));  // lowercase
    printf("Test '5': %d\n", isalnum('5'));  // digit
    printf("Test '#': %d\n", isalnum('#'));  // symbol
    printf("Test ' ': %d\n", isalnum(' '));  // space
    return 0;
}
*/
