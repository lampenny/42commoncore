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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
/*
int	main()
{
const char *test = "hello world";

printf("%s\n", ft_strchr(test, 'e'));
printf("Real strchr:    %s\n", strchr(test, 'e'));
return (0);
}
*/
