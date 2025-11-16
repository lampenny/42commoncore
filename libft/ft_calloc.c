/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:31:59 by penlam            #+#    #+#             */
/*   Updated: 2025/11/16 20:03:22 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr1;
	size_t	total_size;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	ptr1 = malloc(total_size);
	if (ptr1 == NULL)
		return (NULL);
	ft_memset(ptr1, 0, total_size);
	return (ptr1);
}
/*
int main ()
{
char	*ptr;
size_t len;
len = 50;
ptr = (char *)ft_calloc(len, sizeof(char));

if (ptr == NULL) {
	printf("Could not allocate memory");
	exit(1);
}
ft_strlcpy(ptr, "Penny learns C", len);
printf("%s\n", ptr);
free(ptr);

ptr = (char *)ft_calloc(SIZE_MAX, SIZE_MAX);
   if (ptr == NULL)
        printf("Overflow correctly detected (returned NULL)\n");
    else
    {
        printf("ERROR: ft_calloc should have returned NULL!\n");
        free(ptr);
    }

return (0);
}
*/
