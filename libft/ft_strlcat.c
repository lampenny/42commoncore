/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penlam <penlam@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:31:07 by penlam            #+#    #+#             */
/*   Updated: 2025/11/07 10:03:01 by penlam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	i = 0;

	s_len = strlen(src);
	d_len = strlen(dst);
	// 3. overflow check
	if (d_len >= size)
	{
		printf("inside if statement d_len == size \n");

		return d_len + s_len;
	}

	// Here we are copying from the end of the current destination string (d_len)
// the loop stops if the source ends and if the write index reaches the position reserved for the final null terminator (size -1)
	while (src[i] != '\0' && (d_len + i) < (size -1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	printf("d_len + s_len = %zu\n", d_len + s_len);
	return (d_len + s_len);
}
int main()
{
char buf1[20] = "Hello\0";
//char buf2[10] = "World";
char buf3[10] = "Gruesome\0";

//printf("buf1 len(expect 5): %zu\n", safe_strlen(buf1, 10));

printf("buf1: %s\n buf 3:%s\n", buf1, buf3);
printf("buf3 my ft_strlcat: %lu\n", ft_strlcat(buf1, buf3, 20));
printf("buf1: %s buf 3:%s\n", buf1, buf3);

printf("buf3 sys strlcat: %lu\n", strlcat(buf1, buf3, 20));
printf("buf1 SYS: %s buf 3 sys:%s\n", buf1, buf3);

return 0;
}

/*
1. find the current length of dst but stop if reaching 'size'
2. find length of src
3. if theres no space left in dst (its full or size == 0)
	means no concatenation possible
4. calculate how much space is left excluding null terminator
5. copy from src in to dst while there's space
6. null terminate dst
return total length that would have been created.

NOTES:
%zu printf format specifier for size_t
*/
