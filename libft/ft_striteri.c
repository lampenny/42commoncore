void	ft_striteri(char *str, void (*func)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!str || !func)
		return ;
	while (str[i])
	{
		func(i, &str[i]);
		i++;
	}
}
