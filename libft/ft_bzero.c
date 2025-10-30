/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:00:56 by penlam            #+#    #+#             */
/*   Updated: 2025/10/27 17:19:36 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ch;

	ch = s;
	while (n > 0)
	{
		*ch++ = 0;
		n--;
	}
}
/*
#include <stdio.h>
int main()
{
char test_arr[10] = "HELLOHELLO";
size_t length = 10;

printf("initial state: %s\n", test_arr);

size_t bytes_to_clear = 5;
printf("clearing bytes %zu", bytes_to_clear);

ft_bzero(test_arr, bytes_to_clear);

// loop and check byte by byte as part of the array is zeroed
for (size_t i = 0; i < length; i++)
    {
        // Check if the byte is 0 (cleared) or still the original letter.
        if (test_arr[i] == 0)
            printf(" %zu    | 0 (CLEARED)\n", i);
        else
            printf(" %zu    | %c (STILL PRESENT)\n", i, test_arr[i]);
    }

if (test_arr[0] == 0 && test_arr[4] == 0 && test_arr[5] == 'H')
        printf("\nTEST RESULT: PASS!\n");
    else
        printf("\nTEST RESULT: FAIL! (Memory was not cleared correctly.)\n");

    return 0;
}
*/
